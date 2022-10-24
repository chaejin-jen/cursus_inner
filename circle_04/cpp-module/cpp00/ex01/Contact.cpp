#include "Contact.hpp"

Contact::Contact(void) : _idx(0) {}
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

int (Contact::*setFncPtr[5])(std::string){
	this->setFncPtr[0] = this->setFirstname;
	//this->setLastname
	//this->setNickname
	//this->setPhoneNb
	//this->setSecret
}

int Contact::setIdx(int idx) {
	this->_idx = idx;
	return (0);
}

int Contact::setFirstname(std::string str) {
	if (str.empty()){
		std::cout << "First name empty." << std::endl;
		return 1;
	}
	this->_firstName = str;
	return 0;
}

int Contact::setLastname(std::string str) {
	if (str.empty()){
		std::cout << "Last name empty." << std::endl;
		return 1;
	}
	this->_lastName = str;
	return 0;
}

int Contact::setNickname(std::string str) {
	if (str.empty()){
		std::cout << "Nickname empty." << std::endl;
		return 1;
	}
	this->_nickname = str;
	return 0;
}

int Contact::setPhoneNb(std::string str) {
	if (str.empty()){
		std::cout << "Phone number empty." << std::endl;
		return 1;
	}
	this->_phoneNb = str;
	return 0;
}

int Contact::setSecret(std::string str) {
	this->_secret = str;
	return 0;
}
