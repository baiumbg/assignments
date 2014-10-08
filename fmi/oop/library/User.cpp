#include "User.h"
#include <string>
#include <vector>

User::User(std::string username, std::string password, bool access)
{
	this->username = username;
	this->password = password;
	this->access = access;
}

User::User(std::vector<std::string> details)
{
	username = details.at(0);
	password = details.at(1);
	if(details.at(2) == "true") access = true;
	else access = false;
}

std::string User::getUsername()
{
	return username;
}

std::string User::getPassword()
{
	return password;
}

bool User::isAdmin()
{
	return access;
}

void User::setUsername(std::string username)
{
	this->username = username;
}

void User::setPassword(std::string password)
{
	this->password = password;
}

void User::promote()
{
	access = true;
}

void User::demote()
{
	access = false;
}