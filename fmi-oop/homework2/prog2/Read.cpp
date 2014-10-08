#include <iostream>
#include "Read.h"

Formula* Read::clone() const
{
	Formula* _clone = new Read;
	return _clone;
}

double Read::value() const
{
	double _value;
	std::cin>>_value;
	return _value;
}

void Read::print()
{
	std::cout<<"Read";
}