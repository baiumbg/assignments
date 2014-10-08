#pragma once
#include "Contact.h"
#include "Dictionary.h"

class ContactBook
{
private:
	Dictionary<std::string, Contact*> names;
	Dictionary<std::string, Contact*> numbers;
	Dictionary<int, Contact*> ids;
public:
	void addContact(std::string, std::string, int);
	void addContact(Contact&);
	const Contact& findContactByName(std::string);
	const Contact& findContactByNumber(std::string);
	const Contact& findContactById(int);
	void printByName();
	void printByNumber();
	void printById();
	static Contact contactNotFound;
};