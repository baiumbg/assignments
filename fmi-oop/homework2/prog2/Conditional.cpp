#include <iostream>
#include "Conditional.h"

Conditional::Conditional(Formula* _condition, Formula* _whenTrue, Formula* _whenFalse)
{
	condition = _condition->clone();
	whenTrue = _whenTrue->clone();
	whenFalse = _whenFalse->clone();
}

Conditional::Conditional(const Conditional& other)
{
	*this = other;
	//condition = other.condition->clone();
	//whenTrue = other.whenTrue->clone();
	//whenFalse = other.whenFalse->clone();
}

Formula* Conditional::clone() const
{
	Formula* _clone = new Conditional(condition, whenTrue, whenFalse);
	return _clone;
}

double Conditional::value() const
{
	if(condition->value()) return whenTrue->value();
	return whenFalse->value();
}

void Conditional::print()
{
	std::cout<<"if ( ";
	condition->print();
	std::cout<<" ) then ";
	whenTrue->print();
	std::cout<<" else ";
	whenFalse->print();
}

Conditional& Conditional::operator=(const Conditional& other)
{
	if(condition != NULL) delete condition;
	if(whenTrue != NULL) delete whenTrue;
	if(whenFalse != NULL) delete whenFalse;
	condition = other.condition->clone();
	whenTrue = other.whenTrue->clone();
	whenFalse = other.whenFalse->clone();
	return *this;
}

Conditional::~Conditional()
{
	delete condition;
	delete whenTrue;
	delete whenFalse;
}