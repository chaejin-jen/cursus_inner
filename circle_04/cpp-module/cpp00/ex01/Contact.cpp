#include "Contact.hpp"

Contact::Contact(void) : _idx(0) {
	_setFncPtr[0] = &Contact::setFirstname;
	_setFncPtr[1] = &Contact::setLastname;
	_setFncPtr[2] = &Contact::setNickname;
	_setFncPtr[3] = &Contact::setPhoneNb;
	_setFncPtr[4] = &Contact::setSecret;
}
Contact::~Contact(void) {}

int Contact::getIdx(void) const {
	return (this->_idx);
}

std::string Contact::getFirstname(void) const {
	return ((this->_idx == 0) ? "" : _firstName);
}
std::string Contact::getLastname(void) const {
	return ((this->_idx == 0) ? "" : _lastName);
}
std::string Contact::getNickname(void) const {
	return ((this->_idx == 0) ? "" : _nickname);
}
std::string Contact::getPhoneNb(void) const {
	return ((this->_idx == 0) ? "" : _phoneNb);
}
std::string Contact::getSecret(void) const {
	return ((this->_idx == 0) ? "" : _secret);
}

int Contact::setAll(void) {
	int i;
	std::string str[5];

	i = 0;
	while (i < 5)
	{
		str[i] = _getline();
		if (!str[i].empty())
		{
			if (i == 3)
			{
				str[i] = this->_changePNb(str[i]);
				if (str[i].empty())
					continue;
			}
			i++;
		}
		if (std::cin.eof())
			return 1;
	}
	i = -1;
	while (++i < 5)
		(this->*_setFncPtr[i])(str[i]);
	return 0;
}

int Contact::setIdx(int idx) {
	this->_idx = idx;
	return 0;
}

int Contact::setFirstname(const std::string str) {
	if (!std::cin.eof() && str.empty()){
		std::cout << "First name empty." << std::endl;
		return 1;
	}
	this->_firstName = str;
	return 0;
}

int Contact::setLastname(const std::string str) {
	if (!std::cin.eof() && str.empty()){
		std::cout << "Last name empty." << std::endl;
		return 1;
	}
	this->_lastName = str;
	return 0;
}

int Contact::setNickname(const std::string str) {
	if (!std::cin.eof() && str.empty()){
		std::cout << "Nickname empty." << std::endl;
		return 1;
	}
	this->_nickname = str;
	return 0;
}

int Contact::setPhoneNb(const std::string str) {
	if (!std::cin.eof() && str.empty()){
		std::cout << "Phone number empty." << std::endl;
		return 1;
	}
	this->_phoneNb = str;
	return 0;
}

int Contact::setSecret(const std::string str) {
	if (!std::cin.eof() && str.empty()){
		std::cout << "Secret empty." << std::endl;
		return 1;
	}
	this->_secret = str;
	return 0;
}


std::string	Contact::_getline(void) const
{
	std::string str;
	std::getline(std::cin, str);
	if (!std::cin.eof() && !std::cin){
		std::cin.clear();
		str = "";
	}
	return str;
}

std::string	Contact::_changePNb(std::string str)
{
	std::string pnb = "";

	for (size_t i = 0; i < str.length(); i++){
		if (str[i] >= '0' && str[i] <= '9')
			pnb += str[i];
	}
	if (pnb.empty()){
		std::cout << "(phone number)No number" << std::endl;
		return "";
	}
	return pnb;
}
