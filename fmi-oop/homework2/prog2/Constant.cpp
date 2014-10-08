#include <iostream>
#include "Constant.h"

Constant::Constant(double _value)
{
	this->_value = _value;
}

Formula* Constant::clone() const
{
	Formula* _clone = new Constant(_value);
	return _clone;
}

double Constant::value() const
{
	return _value;
}

void Constant::print()
{
	std::cout<<_value;
}