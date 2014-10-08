#pragma once
#include <vector>
#include <string>

class User
{
private:
	std::string username;
	std::string password;
	bool access;
public:
	User(std::string, std::string, bool = false);
	User(std::vector<std::string>);
	std::string getUsername();
	std::string getPassword();
	bool isAdmin();
	void setUsername(std::string);
	void setPassword(std::string);
	void promote();
	void demote();
};