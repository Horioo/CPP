/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:54:09 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/04/01 11:42:11 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int verifyValue(double value, std::vector<std::pair<std::string, double> >*inputData){
	if(value < 0){
		std::string errormsg = "Error: not a positive Number";
			inputData->push_back(std::make_pair(errormsg, -1));
		return 0;
	}
	if(value > INT_MAX){
		std::string errormsg = "Error: too large a number";
			inputData->push_back(std::make_pair(errormsg, -1));
		return 0;
	}
	return 1;
}

int verifyDate(std::string date, std::vector<std::pair<std::string, double> >*inputData){

	size_t start = 0;
	size_t end = date.find('-');

	std::string strDay;
	std::string strMonth;
	std::string strYear;

	strYear = date.substr(start, end - start);
	start = end + 1;
	end = date.find('-', start);
	strMonth = date.substr(start, end - start);
	start = end + 1;
	end = date.find('-', start);
	strDay = date.substr(start, end - start);
	start = end + 1;
	end = date.find('-', start);

	int year = atoi(strYear.c_str());
	int month = atoi(strMonth.c_str());
	int day = atoi(strDay.c_str());

	//2009 baseado no data.csv
	if(year < 2009 || (month > 12 || month < 1) || (day > 31 || day < 1)){
		std::string errormsg = "Error: bad input => ";
		errormsg.append(date);
			inputData->push_back(std::make_pair(errormsg, -1));
		return 0;	
	}
	switch (month)
	{
	case 2:
		if(year % 4 == 0 && day > 29){
			std::string errormsg = "Error: bad input => ";
			errormsg.append(date);
			inputData->push_back(std::make_pair(errormsg, -1));
			return 0;
		}
		else if(year % 4 != 0 && day > 28){
			std::string errormsg = "Error: bad input => ";
			errormsg.append(date);
			inputData->push_back(std::make_pair(errormsg, -1));
			return 0;
		}
		break;
	case 4: case 6: case 9: case 11:
		if(day > 30){
			std::string errormsg = "Error: bad input => ";
			errormsg.append(date);
			inputData->push_back(std::make_pair(errormsg, -1));
			return 0;	
		}
		break;
	}
	return 1;
}

int verifyValueStr(std::string valueStr, std::vector<std::pair<std::string, double> >*inputData){
	
	for (size_t i = 0; i < valueStr.length(); ++i) {
        char c = valueStr[i];
        if (!((c >= '0' && c <= '9') || c == '.' || c == ' ')) {
			std::string errormsg = "Error: Can't use Characters";
			inputData->push_back(std::make_pair(errormsg, -1));
            return false;
        }
    }
    return true;
}

std::string trim(const std::string& str) {
    
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return ""; 

    size_t end = str.find_last_not_of(" \t\n\r");

    return str.substr(start, end - start + 1);
}

std::vector<std::pair<std::string, double> > getDataCSV(const char *fileToOpen){
	std::vector<std::pair<std::string, double> >btcData;
	std::ifstream file(fileToOpen);

	if(!file.is_open()){
		std::cerr << "Error on Opening File" << std::endl;
	}

	std::string line;

	std::getline(file, line);
	while(std::getline(file, line)){
		std::stringstream ss(line);
		std::string date, valueStr;
		double value;
			
		if(std::getline(ss, date, ',') && std::getline(ss, valueStr)){
			value = atof(valueStr.c_str());
			btcData.push_back(std::make_pair(date, value));
		}
	}
	file.close();
	return btcData;
}

std::vector<std::pair<std::string, double> > getDataTXT(const char *fileToOpen){
	std::vector<std::pair<std::string, double> >inputData;
	std::ifstream file(fileToOpen);

	if(!file.is_open()){
		std::cerr << "Error on Opening File" << std::endl;
	}

	std::string line;

	std::getline(file, line);
	while(std::getline(file, line)){
		std::stringstream ss(line);
		std::string date, valueStr;
		double value;
			
		if(std::getline(ss, date, '|') && std::getline(ss, valueStr)){
			value = atof(valueStr.c_str());

			if(verifyValue(value, &inputData) && verifyDate(date, &inputData) && verifyValueStr(valueStr, &inputData)){
				inputData.push_back(std::make_pair(trim(date), value));
			}
		}
		else{
			std::string errormsg = "Error: bad input => ";
			errormsg.append(line);
			inputData.push_back(std::make_pair(errormsg, -1));
		}
	}
	file.close();
	return inputData;
}

void display(std::vector<std::pair<std::string, double> >d){
	for(std::vector<std::pair<std::string, double> >::iterator it = d.begin(); it != d.end(); ++it){	
		std::cout << "Date: " << it->first << " | Value " << it->second << std::endl; 
	}
}

struct CompareDates {
    bool operator()(const std::pair<std::string, double>& entry, const std::string& date) const {
        return entry.first < date;
    }
};

int main(int ac, char **av){
	if(ac == 2){
		int foundFlag = 0;
		std::vector<std::pair<std::string, double> >btcData = getDataCSV("data.csv");
		std::vector<std::pair<std::string, double> >inputData = getDataTXT(av[1]);


		for(std::vector<std::pair<std::string, double> >::iterator itInput = inputData.begin(); itInput != inputData.end(); itInput++){
			foundFlag = 0;
			
			if(itInput->second == -1)
					std::cerr << itInput->first << std::endl;
			else
			{	
				std::vector<std::pair<std::string, double> >::iterator itBTC;
				for( itBTC = btcData.begin(); itBTC != btcData.end(); itBTC++){
					if(itBTC->first == itInput->first){
						foundFlag = 1;
						std::cout << itInput->first << " => " << itInput->second << " = " << itInput->second * itBTC->second << std::endl;
						break;
					}
				}
				if(foundFlag == 0){
					
					itBTC = std::lower_bound(btcData.begin(), btcData.end(), *itInput);
					
					//If the value returned is not equal to the BTC Date we go one back so we find the closest date
					if(itBTC != btcData.begin() && (itBTC == btcData.end() || itBTC->first != itInput->first))
						--itBTC;
					//After that we do the calculation with the correct Date
					if(itBTC != btcData.end() && itBTC->first <= itInput->first)
						std::cout << itInput->first << " => " << itInput->second << " = " << itInput->second * itBTC->second << std::endl;
					else
						std::cout << "No Valid Date for " << itInput->first << std::endl;
				}
			}
		}
	}
	else 
		std::cout << "Invalid number of files: \nFormat: ./btc FileWithValuesToEvaluate " << std::endl;

}