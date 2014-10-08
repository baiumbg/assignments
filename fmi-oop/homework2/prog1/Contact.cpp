#include <iostream>
#include "Contact.h"

Contact::Contact(std::string _name, std::string _number, int _id)
{
	name = _name;
	number = _number;
	id = _id;
}

void Contact::setName(std::string _name)
{
	name = _name;
}

void Contact::setNumber(std::string _number)
{
	number = _number;
}

void Contact::setId(int _id)
{
	id = _id;
}

std::string Contact::getName()
{
	return name;
}

std::string Contact::getNumber()
{
	return number;
}

int Contact::getId()
{
	return id;
}

std::ostream& operator<<(std::ostream& out, Contact contact)
{
	out << contact.id << ": " << contact.name<< " - " << contact.number << std::endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, Contact* contact)
{
	out << contact->id << ": " << contact->name<< " - " << contact->number << std::endl;
	return out;
}