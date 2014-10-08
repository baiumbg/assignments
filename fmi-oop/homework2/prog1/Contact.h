#pragma once
#include <string>

class Contact
{
private:
	std::string name;
	std::string number;
	int id;
public:
	Contact();
	Contact(std::string, std::string, int);
	void setName(std::string);
	void setNumber(std::string);
	void setId(int);
	std::string getName();
	std::string getNumber();
	int getId();
	friend std::ostream& operator<<(std::ostream&, Contact);
	friend std::ostream& operator<<(std::ostream&, Contact*);
};