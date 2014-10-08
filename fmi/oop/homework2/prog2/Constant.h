#pragma once
#include "Formula.h"

class Constant : public Formula
{
private:
	double _value;
public:
	Constant(double);
	virtual double value() const;
	virtual void print();
	Formula* clone() const;
};