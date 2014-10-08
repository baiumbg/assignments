#pragma once
#include "Formula.h"

class BinaryOperation : public Formula
{
private:
	Formula* first;
	Formula* second;
	char operation;
public:
	BinaryOperation(Formula*, Formula*, char);
	BinaryOperation(const BinaryOperation&);
	double value() const;
	void print();
	Formula* clone() const;
	BinaryOperation& operator=(const BinaryOperation&);
	~BinaryOperation();
};