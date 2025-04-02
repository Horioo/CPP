/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:39:06 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/04/02 12:44:28 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *file){
	std::cout << "BitcoinExchange Default Constructor" << std::endl;
	this->btcData = getDataCSV("data.csv");
	this->inputData = getDataTXT(file);
	this->foundFlag = 0;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout << "BitcoinExchange Destructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
	std::cout << "BitcoinExchange Copy Constructor" << std::endl;
	this->btcData = other.btcData;
	this->inputData = other.inputData;
	this->foundFlag = other.foundFlag;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy){
	if(this != &copy){
		std::cout << "BitcoinExchange Copy Operator" << std::endl;
		this->btcData = copy.btcData;
		this->inputData = copy.inputData;
		this->foundFlag = copy.foundFlag;
	}
	return *this;
}

std::vector<std::pair<std::string, double> > BitcoinExchange::getDataCSV(const char *fileToOpen){
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
			this->btcData.push_back(std::make_pair(date, value));
		}
	}
	file.close();
	return btcData;
}

std::vector<std::pair<std::string, double> > BitcoinExchange::getDataTXT(const char *fileToOpen){
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

			if(verifyValue(value, &this->inputData) && verifyDate(date, &this->inputData) && verifyValueStr(valueStr, &this->inputData)){
				this->inputData.push_back(std::make_pair(trim(date), value));
			}
		}
		else{
			std::string errormsg = "Error: bad input => ";
			errormsg.append(line);
			this->inputData.push_back(std::make_pair(errormsg, -1));
		}
	}
	file.close();
	return this->inputData;
}

std::string BitcoinExchange::trim(const std::string& str) {
    
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return ""; 

    size_t end = str.find_last_not_of(" \t\n\r");

    return str.substr(start, end - start + 1);
}

int BitcoinExchange::verifyValueStr(std::string valueStr, std::vector<std::pair<std::string, double> >*inputData){
	
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

int BitcoinExchange::verifyDate(std::string date, std::vector<std::pair<std::string, double> >*inputData){

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
	bool  leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	switch (month)
	{
	case 2:
		if(leapYear && day > 29){
			std::string errormsg = "Error: bad input => ";
			errormsg.append(date);
			inputData->push_back(std::make_pair(errormsg, -1));
			return 0;
		}
		else if(!leapYear && day > 28){
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

int BitcoinExchange::verifyValue(double value, std::vector<std::pair<std::string, double> >*inputData){
	if(value < 0){
		std::string errormsg = "Error: not a positive Number";
			inputData->push_back(std::make_pair(errormsg, -1));
		return 0;
	}
	if(value > 1000){
		std::string errormsg = "Error: too large a number";
			inputData->push_back(std::make_pair(errormsg, -1));
		return 0;
	}
	return 1;
}

void BitcoinExchange::display(){
	for(std::vector<std::pair<std::string, double> >::iterator itInput = this->inputData.begin(); itInput != this->inputData.end(); itInput++){
		this->foundFlag = 0;
			
		if(itInput->second == -1)
			std::cerr << itInput->first << std::endl;
		else
		{	
			std::vector<std::pair<std::string, double> >::iterator itBTC;
			for( itBTC = this->btcData.begin(); itBTC != this->btcData.end(); itBTC++){
				if(itBTC->first == itInput->first){
					this->foundFlag = 1;
					std::cout << itInput->first << " => " << itInput->second << " = " << itInput->second * itBTC->second << std::endl;
					break;
				}
			}
			if(this->foundFlag == 0){
				
				itBTC = std::lower_bound(this->btcData.begin(), this->btcData.end(), *itInput);
				
				//If the value returned is not equal to the BTC Date we go one back so we find the closest date
				if(itBTC != this->btcData.begin() && (itBTC == this->btcData.end() || itBTC->first != itInput->first))
					--itBTC;
				//After that we do the calculation with the correct Date
				if(itBTC != this->btcData.end() && itBTC->first <= itInput->first)
					std::cout << itInput->first << " => " << itInput->second << " = " << itInput->second * itBTC->second << std::endl;
				else
					std::cout << "No Valid Date for " << itInput->first << std::endl;
			}
		}
	}
}