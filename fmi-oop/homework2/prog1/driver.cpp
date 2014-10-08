#include <iostream>
#include <string>
#include "Contact.h"
#include "Dictionary.h"
#include "ContactBook.h"
using namespace std;

int main()
{
	ContactBook test;
	test.addContact("Vazo", "0896072713", 1);
	test.addContact("Idzko", "0899571638", 2);
	test.addContact("Didgo", "0887263417", 3);
	//test.printByName();
	cout<<test.findContactById(9);
	return 0;
}