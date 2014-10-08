#include "ContactBook.h"
#include "Contact.h"

Contact ContactBook::contactNotFound = Contact("Contact not found.", "???", -1);

void ContactBook::addContact(std::string name, std::string number, int id)
{
	Contact* newContact = new Contact(name, number, id);
	names.addEntry(name, newContact);
	numbers.addEntry(number, newContact);
	ids.addEntry(id, newContact);
}

void ContactBook::addContact(Contact& contact)
{
	Contact* newContact = new Contact(contact);
	names.addEntry(contact.getName(), newContact);
	numbers.addEntry(contact.getNumber(), newContact);
	ids.addEntry(contact.getId(), newContact);
}

const Contact& ContactBook::findContactByName(std::string name)
{
	Contact** search = names.findValue(name);
	if (search != NULL) return **search;
	return contactNotFound;
}

const Contact& ContactBook::findContactByNumber(std::string number)
{
	Contact** search = numbers.findValue(number);
	if (search != NULL) return **search;
	return contactNotFound;
}

const Contact& ContactBook::findContactById(int id)
{
	Contact** search = ids.findValue(id);
	if (search != NULL) return **search;
	return contactNotFound;
}

void ContactBook::printByName()
{
	Dictionary<std::string, Contact*> tempBook = names;
	tempBook.print();
}

void ContactBook::printByNumber()
{
	Dictionary<std::string, Contact*> tempBook = numbers;
	tempBook.print();
}

void ContactBook::printById()
{
	Dictionary<int, Contact*> tempBook = ids;
	tempBook.print();
}