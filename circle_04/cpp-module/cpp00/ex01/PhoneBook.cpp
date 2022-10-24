#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void) : _nb(0), _oldestIdx(0) {}
PhoneBook::~PhoneBook(void) {}

int	PhoneBook::add(void)
{
	int			idx;
	Contact 	*contact;
	std::string str[5];

	idx = this->_nb != 8 ? this->_nb : this->_oldestIdx;
	contact = &this->_contacts[idx];
	while (!std::cin.eof())
	{
		/* code */
	}

	while (!std::cin.eof() && contact->setFirstname(_getline())) {}
	while (!std::cin.eof() && contact->setLastname(_getline())) {}
	while (!std::cin.eof() && contact->setNickname(_getline())) {}
	while (!std::cin.eof() && contact->setPhoneNb(_getline())) {}
	while (!std::cin.eof() && contact->setSecret(_getline())) {}
	contact->setIdx(idx + 1);
	if (this->_nb != 8)
		_nb++;
	else
		_oldestIdx++;
	return 0;
}

void	PhoneBook::search(void) const
{
	this->_display();
}

std::string	PhoneBook::_getline(void) const
{
	std::string str;
	std::getline(std::cin, str);
	if (!std::cin){
		std::cin.clear();
		str = "";
	}
	return str;
}

void	PhoneBook::_putf(std::string str) const
{
	//std::string outstr;
	std::cout << '|';
	std::cout << std::setw(10) << std::setfill(' ') << std::right;
	std::cout << (str.length() > 10 ? str.substr(0, 9) + "." : str);
	std::cout << '|';
}

void	PhoneBook::_display(void) const
{
	std::cout << "+-------------------------------------------+\n";
	std::cout << "|     Index|First name| Last name|  Nickname|\n";
	std::cout << "+-------------------------------------------+" << std::endl;
	for (int i = 0; i < this->_nb; i++) {
		std::cout << '|';
		std::cout.width(10);
		std::cout.fill(' ');
		std::cout << i + 1;
		std::cout << '|';
		this->_putf(this->_contacts[i].getFirstname());
		this->_putf(this->_contacts[i].getLastname());
		this->_putf(this->_contacts[i].getNickname());
		std::cout << "\n+-------------------------------------------+" << std::endl;
	}
	if (this->_nb == 0)
	{
		std::cout << "|                                           |\n";
		std::cout << "+-------------------------------------------+" << std::endl;
	}
}
