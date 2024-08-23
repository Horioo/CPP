/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:57:11 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/08/23 22:32:39 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void){
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" << "ammount:" << Account::_amount << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::Account(int initial_deposit){
	Account::_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" << "ammount:" << Account::_amount << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" << "ammount:" << Account::_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(){
	return(Account::_nbAccounts);
}

int Account::getTotalAmount(){
	return(Account::_totalAmount);
}

int Account::getNbDeposits(){
	return(Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(){
	return(Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(){
	time_t rawtime;
  	struct tm * timeinfo;
	char f_time [80];
	
	time (&rawtime);
 	timeinfo = localtime (&rawtime);
	
	strftime(f_time, 80,"%Y%m%d_%H%M%S",timeinfo);
	std::cout << "[" << f_time << "] ";
}

void Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit){
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount +=deposit;
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" << "p_ammount:" << Account::_amount << ";deposit:" << deposit << ";ammount:" << Account::_amount + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal){
	if(withdrawal > this->_amount)
	{
		_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ";" << "p_ammount:" << Account::_amount << ";withdrawal:refused"<< std::endl;
		return (false);
	}
	else
	{
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ";" << "p_ammount:" << Account::_amount << ";withdrawal:" << withdrawal << ";amount:" << Account::_amount - withdrawal << ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
		Account::_amount -= withdrawal;
		return (true);
	}
}

void Account::displayStatus() const{
	_displayTimestamp();
	std::cout  << "index:" << Account::_accountIndex << ";" << "ammount:" << Account::_amount << ";deposit:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


