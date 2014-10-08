#pragma once
#include "Formula.h"

class Read : public Formula
{
public:
	double value() const;
	void print();
	Formula* clone() const;
};