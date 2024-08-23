/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:57:11 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/08/23 18:33:06 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

/*Account Creation
[Timestamp] index:_accountIndex;amount:_amount;created*/

Account::Account(void){
	std::time_t current_time = std::time(0);
	std::cout << "[" << current_time << "] " << "index:" << Account::_accountIndex << ";" << "ammount:" << Account::_amount << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::Account(int initial_deposit){
	std::time_t current_time = std::time(0);
	Account::_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	std::cout << "[" << current_time << "] " << "index:" << Account::_accountIndex << ";" << "ammount:" << Account::_amount << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account(void){
	std::time_t current_time = std::time(0);
	std::cout << "[" << current_time << "] " << "index:" << Account::_accountIndex << ";" << "ammount:" << Account::_amount << ";closed" << std::endl;
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

void Account::displayAccountsInfos(){
	std::time_t current_time = std::time(0);
	std::cout << "[" << current_time << "] " << "accounts:" << Account::_nbAccounts << ";" << "total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit){
	std::time_t current_time = std::time(0);
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount +=deposit;
	std::cout << "[" << current_time << "] " << "index:" << Account::_accountIndex << ";" << "p_ammount:" << Account::_amount << ";deposit:" << deposit << ";ammount:" << Account::_amount + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal){
	std::time_t current_time = std::time(0);
	if(withdrawal > this->_amount)
	{
		std::cout << "[" << current_time << "] " << "index:" << Account::_accountIndex << ";" << "p_ammount:" << Account::_amount << ";withdrawal:refused"<< std::endl;
		return (false);
	}
	else
	{
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << "[" << current_time << "] " << "index:" << Account::_accountIndex << ";" << "p_ammount:" << Account::_amount << ";withdrawal:" << withdrawal << ";amount:" << Account::_amount - withdrawal << ";nb_withdrawals:" << Account::getNbWithdrawals << std::endl;
		return (true);
	}
}

void Account::displayStatus() const{
	std::time_t current_time = std::time(0);
	std::cout << "[" << current_time << "] " << "index:" << Account::_accountIndex << ";" << "ammount:" << Account::_amount << ";deposit:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


