#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits.h>
#include <ctime>
#include <vector>


class BitcoinExchange {

	private:
	std::vector<std::pair<std::string, double> >btcData;
	std::vector<std::pair<std::string, double> >inputData;
	int foundFlag;

	public:
	BitcoinExchange(const char *file);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &copy);

	std::vector<std::pair<std::string, double> > getDataTXT(const char *fileToOpen);
	std::vector<std::pair<std::string, double> > getDataCSV(const char *fileToOpen);
	std::string trim(const std::string& str);
	int verifyValueStr(std::string valueStr, std::vector<std::pair<std::string, double> >*inputData);
	int verifyDate(std::string date, std::vector<std::pair<std::string, double> >*inputData);
	int verifyValue(double value, std::vector<std::pair<std::string, double> >*inputData);

	void display();
};

#endif