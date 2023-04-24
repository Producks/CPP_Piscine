#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//[19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << \
	this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() \
	<< ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" \
	<< Account::getNbWithdrawals() << std::endl; 
}

// Format:  YYYYMMDD_HHMMSS
// example: [19920104_091532]
void Account::_displayTimestamp(void)
{
	std::time_t current_time = std::time(NULL);
	std::tm* time_struct = std::localtime(&current_time);
	std::ostringstream date_stream;
	date_stream << "[" 
				<< std::setw(4) << std::setfill('0') << time_struct->tm_year + 1900 
				<< std::setw(2) << std::setfill('0') << time_struct->tm_mon + 1
				<< std::setw(2) << std::setfill('0') << time_struct->tm_mday 
				<< '_'
				<< std::setw(2) << std::setfill('0') << time_struct->tm_hour
				<< std::setw(2) << std::setfill('0') << time_struct->tm_min
				<< std::setw(2) << std::setfill('0') << time_struct->tm_sec 
				<< "] ";
	std::string date_string = date_stream.str();
	std::cout << date_string;
}

//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false ;
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << \
		";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return true ;
	}
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" \
	<< this->_nbDeposits << ";withdrawwals:" << this->_nbWithdrawals << std::endl;
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount \
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

