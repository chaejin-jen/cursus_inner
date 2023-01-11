#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	if (initial_deposit < 0 || _nbAccounts == INT_MAX
		|| Account::_totalAmount > INT_MAX - initial_deposit)
	{
		std::cout << "index:" << Account::_nbAccounts \
		<< ";amount:" << initial_deposit \
		<< ";create refused" << std::endl;
		return ;
	}
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->_amount << ";created" \
		<< std::endl;
}
Account::~Account( void ){
	Account::_nbAccounts--; // 사라진 어카운트.. 인덱스 꼬일텐데...
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->_amount
		<< ";closed" << std::endl;
}

int	Account::getNbAccounts( void ){return Account::_nbAccounts;}
int	Account::getTotalAmount( void ){return Account::_totalAmount;}
int	Account::getNbDeposits( void ){return Account::_totalNbDeposits;}
int	Account::getNbWithdrawals( void ){return Account::_totalNbWithdrawals;}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() \
		<< ";total:" << Account::getTotalAmount() \
		<< ";deposits:" << Account::getNbDeposits() \
		<< ";withdrawals:" << Account::getNbWithdrawals() \
		<< std::endl;
}

void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	if (deposit < 1
		|| Account::_totalAmount > INT_MAX - deposit
		|| this->_amount > INT_MAX - deposit
		|| _nbDeposits == INT_MAX
		|| this->_nbDeposits == INT_MAX)
	{
		std::cout << "index:" << this->_accountIndex \
			<< ";p_amount:" << this->_amount \
			<< ";deposit:refused" << std::endl;
		return ;
	}
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex \
		<< ";p_amount:" << this->_amount - deposit \
		<< ";deposit:" << deposit \
		<< ";amount:" << this->_amount \
		<< ";nb_deposits:" << this->_nbDeposits \
		<< std::endl;
}
bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	if (withdrawal < 1
		|| this->_amount < withdrawal
		|| Account::_totalAmount < withdrawal
		|| Account::_totalNbWithdrawals == INT_MAX
		|| this->_nbWithdrawals == INT_MAX)	
	{
		std::cout << "index:" << this->_accountIndex \
			<< ";p_amount:" << this->_amount \
			<< ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << "index:" << this->_accountIndex \
		<< ";p_amount:" << this->_amount + withdrawal \
		<< ";withdrawal:" << withdrawal \
		<< ";amount:" << this->_amount \
		<< ";nb_withdrawals:" << this->_nbWithdrawals \
		<< std::endl;
	return true;
}
int		Account::checkAmount( void ) const{
	std::cout << "checkAmount" << std::endl;
	return 0;
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->_amount 
		<< ";deposits:" << this->_nbDeposits \
		<< ";withdrawals:" << this->_nbWithdrawals \
		<< std::endl;
}

void	Account::_displayTimestamp( void ){
	std::time_t curr_time;
	std::tm * timeinfo;
	char time_buffer[100];
	
	std::time(&curr_time);
	timeinfo = localtime(&curr_time);
	
	strftime(time_buffer, 50, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << '[' << time_buffer << "] ";
}