#include <iostream>
#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(Formula* _first, Formula* _second, char _operation)
{
	first = _first->clone();
	second = _second->clone();
	operation = _operation;
}

BinaryOperation::BinaryOperation(const BinaryOperation& other)
{
	*this = other;
}

Formula* BinaryOperation::clone() const
{
	Formula* _clone = new BinaryOperation(first, second, operation);
	return _clone;
}

double BinaryOperation::value() const
{
	switch(operation)
	{
		case '+':
			return first->value() + second->value();
		case '-':
			return first->value() - second->value();
		case '*':
			return first->value() * second->value();
		case '/':
			return first->value() / second->value();
		case '<':
			return first->value() < second->value();
		case '=':
			return first->value() == second->value();
	}
}

void BinaryOperation::print()
{
	std::cout<<"( ";
	first->print();
	std::cout<<' '<<operation<<' ';
	second->print();
	std::cout<<" )";
}

BinaryOperation& BinaryOperation::operator=(const BinaryOperation& other)
{
	if(first != NULL) delete first;
	if(second != NULL) delete second;
	first = other.first->clone();
	second = other.second->clone();
	operation = other.operation;
	return *this;
}

BinaryOperation::~BinaryOperation()
{
	delete first;
	delete second;
}