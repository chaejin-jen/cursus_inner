#include "Contact.hpp"

Contact::Contact(void) : _idx(0) {
	_setFncPtr[0] = &Contact::setFirstname;
	_setFncPtr[1] = &Contact::setLastname;
	_setFncPtr[2] = &Contact::setNickname;
	_setFncPtr[3] = &Contact::setPhoneNb;
	_setFncPtr[4] = &Contact::setSecret;
	_getFncPtr[0] = &Contact::getFirstname;
	_getFncPtr[1] = &Contact::getLastname;
	_getFncPtr[2] = &Contact::getNickname;
	_getFncPtr[3] = &Contact::getPhoneNb;
	_getFncPtr[4] = &Contact::getSecret;
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
	Contact nc;

	i = 0;
	while (i < 5)
	{
		if ((nc.*_setFncPtr[i])(_getline()) == 0)
			i++;
		if (std::cin.eof())
			return 1;
	}
	i = -1;
	while (++i < 5)
		(this->*_setFncPtr[i])((nc.*_getFncPtr[i])());
	return 0;
}

int Contact::setIdx(int idx) {
	this->_idx = idx;
	return 0;
}

int Contact::setFirstname(std::string str) {
	if (!std::cin.eof() && str.empty()){
		std::cout << "First name empty." << std::endl;
		return 1;
	}
	this->_firstName = str;
	return 0;
}

int Contact::setLastname(std::string str) {
	if (!std::cin.eof() && str.empty()){
		std::cout << "Last name empty." << std::endl;
		return 1;
	}
	this->_lastName = str;
	return 0;
}

int Contact::setNickname(std::string str) {
	if (!std::cin.eof() && str.empty()){
		std::cout << "Nickname empty." << std::endl;
		return 1;
	}
	this->_nickname = str;
	return 0;
}

int Contact::setPhoneNb(std::string str) {
	if (!std::cin.eof() && str.empty()){
		std::cout << "Phone number empty." << std::endl;
		return 1;
	}
	this->_phoneNb = str;
	return 0;
}

int Contact::setSecret(std::string str) {
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
