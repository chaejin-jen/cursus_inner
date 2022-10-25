#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	this->_amount = initial_deposit;
	Account::_nbAccounts++;
	Account::_displayTimestamp(); //
}
Account::~Account( void ){
	Account::_nbAccounts--;
}

int	Account::getNbAccounts( void ){return Account::_nbAccounts;}
int	Account::getTotalAmount( void ){return Account::_totalAmount;}
int	Account::getNbDeposits( void ){return Account::_totalNbDeposits;}
int	Account::getNbWithdrawals( void ){return Account::_totalNbDeposits;}
void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	// t
	// std::cout << "index:" << 0<< ";amount:" << 42 << ";created" << std::endl;
}

void	Account::makeDeposit( int deposit ){
	this->_nbDeposits = deposit;
}
bool	Account::makeWithdrawal( int withdrawal ){
	this->_nbWithdrawals = withdrawal;
	return true;
}
int		Account::checkAmount( void ) const{return 0;}
void	Account::displayStatus( void ) const{}

void	Account::_displayTimestamp( void ){
	std::time_t curr_time;
	std::tm * timeinfo;
	char time_buffer[100];
	
	std::time(&curr_time);
	timeinfo = localtime(&curr_time);
	
	strftime(time_buffer, 50, "%Y%m%d_%H%M%S ", timeinfo);
	std::cout << time_buffer;
}