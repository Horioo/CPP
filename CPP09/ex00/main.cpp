/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:54:09 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/31 14:25:22 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Print values on a Map Container

for(std::map<std::string, double>::iterator it = btcData.begin(); it != btcData.end(); ++it){
			
	std::cout << "Data: " << it->first << " | Preco " << it->second << std::endl; 
}
*/

int verifyValue(double value){
	if(value < 0){
		std::cerr << "Error: not a positive Number" << std::endl;
		return 0;
	}
	if(value > INT_MAX){
		std::cerr << "Error: too large a number" << std::endl;
		return 0;
	}
	return 1;
}

int verifyDate(std::string date){

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
		std::cerr << "Error: bad input => " << date << std::endl; 
		return 0;	
	}
	switch (month)
	{
	case 2:
		if(year % 4 == 0 && day > 29){
			std::cerr << "Error : bad input => " << year << "-" << month << "-" << day << std::endl; 
			return 0;
		}
		else if(year % 4 != 0 && day > 28){
			std::cerr << "Error : bad input => " << year << "-" << month << "-" << day << std::endl;
			return 0;
		}
		break;
	case (4, 6, 9, 11):
		if(day > 30){
			std::cerr << "Error : bad input => " << year << "-" << month << "-" << day << std::endl;
			return 0;	
		}
		break;
	}
	return 1;
}

int verifyValueStr(std::string valueStr){
	
	for (size_t i = 0; i < valueStr.length(); ++i) {
        char c = valueStr[i];
		//std::cout << "C = " << c << std::endl;
        if (!((c >= '0' && c <= '9') || c == '.' || c == ' ')) {
			std::cerr << "Error: Can't use Characters" << std::endl;
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

std::multimap<std::string, double> getDataCSV(const char *fileToOpen){
	std::multimap<std::string, double>btcData;
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
			btcData.insert(std::make_pair(date, value));
		}
	}
	file.close();
	return btcData;
}

std::multimap<std::string, double> getDataTXT(const char *fileToOpen){
	std::multimap<std::string, double>btcData;
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

			if(verifyValue(value) && verifyDate(date) && verifyValueStr(valueStr)){
				btcData.insert(std::make_pair(trim(date), value));
				std::cout << date << " => " << value << " = " << "value to do" << std::endl; 
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	file.close();
	return btcData;
}

void display(std::multimap<std::string, double>d){
	for(std::map<std::string, double>::iterator it = d.begin(); it != d.end(); ++it){	
		std::cout << "Data: " << it->first << " | Preco " << it->second << std::endl; 
	}
}


int main(int ac, char **av){
	if(ac == 2){
		int foundFlag = 0;
		std::multimap<std::string, double>btcData = getDataCSV("data.csv");
		std::multimap<std::string, double>inputData = getDataTXT(av[1]);

		for(std::multimap<std::string, double>::iterator it = inputData.begin(); it != inputData.end(); it++){
			foundFlag = 0;
			for(std::multimap<std::string, double>::iterator it2 = btcData.begin(); it2 != btcData.end(); it2++){
				if(it2->first == it->first){
					foundFlag = 1;
					std::cout << it->first << " => " << it->second << " = " << it->second * it2->second << std::endl;
				}
			}
			if(foundFlag == 0){
				//Fazer caso nao tenha encontrado no ciclo em cima, deve procurar pela data mais perto arredondado a baixo
			}
		}
		
	}
	else 
		std::cout << "Invalid number of files: \nFormat: ./btc FileWithValuesToEvaluate " << std::endl;

}