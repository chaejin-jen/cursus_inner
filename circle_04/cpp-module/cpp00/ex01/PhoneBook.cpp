#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(void) : _nb(0), _oldestIdx(0) {}
PhoneBook::~PhoneBook(void) {}

int	PhoneBook::add(void)
{
	int			idx;
	Contact 	*contact;

	idx = this->_nb != 8 ? this->_nb : this->_oldestIdx;
	contact = &this->_contacts[idx];
	if (contact->setAll() != 0)
		return 1;
	contact->setIdx(idx + 1);
	if (this->_nb != 8)
		_nb++;
	else
	{
		_oldestIdx++;
		if (_oldestIdx == 8)
			_oldestIdx = 0;
	}
	return 0;
}

void	PhoneBook::search(void) const
{
	int idx;

	if (this->_nb == 0)
	{
		std::cout << "No data."<< std::endl;
		return ;
	}
	this->_display();
	idx = this->_getidx();
	if (idx != -1)
	{
		std::cout << "first name : "<< this->_contacts[idx].getFirstname();
		std::cout << "\nlast name : "<< this->_contacts[idx].getLastname();
		std::cout << "\nnickname : "<< this->_contacts[idx].getNickname();
		std::cout << "\nphone number : "<< this->_contacts[idx].getPhoneNb();
		std::cout << "\ndarkest secret : "<< this->_contacts[idx].getSecret() << std::endl;
	}
}

void	PhoneBook::_putf(std::string str) const
{
	std::cout << std::setw(10) << std::setfill(' ') << std::right;
	std::cout << (str.length() > 10 ? str.substr(0, 9) + "." : str);
	std::cout << '|';
}

void	PhoneBook::_display(void) const
{
	std::cout << "+-------------------------------------------+\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
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
}

int	PhoneBook::_getidx(void) const
{
	int idx;
	std::string str;

	while (1)
	{
		std::cout << "index : ";
		if (!std::getline(std::cin, str))
		{
			std::cout << std::endl;
			return -1;
		}
		if (!std::cin.eof() && !std::cin){
			std::cin.clear();
			str = "";
			return -1;
		}
		std::stringstream ssInt(str);
		ssInt >> idx;
		if (str.length() == 1 && idx > 0 && idx <= this->_nb)
			break;
		if (str.length() == 1 && str[0] < '9' && (str[0] < '1' || str[0] > ('0' + this->_nb)))
			std::cout << "index is out of range" << std::endl;
		else
			std::cout << "index is wrong" << std::endl;
	}
	return idx - 1;
}
