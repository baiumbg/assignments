#pragma once
#include "Formula.h"

class Conditional : public Formula
{
private:
	Formula* condition;
	Formula* whenTrue;
	Formula* whenFalse;
public:
	Conditional(Formula*, Formula*, Formula*);
	Conditional(const Conditional&);
	double value() const;
	void print();
	Formula* clone() const;
	Conditional& operator=(const Conditional&);
	~Conditional();
};