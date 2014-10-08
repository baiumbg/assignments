#include <iostream>
#include "BinaryOperation.h"
#include "Constant.h"
#include "Read.h"
#include "Conditional.h"

int main()
{
	Constant c1(1);
	Constant* c2 = new Constant(2);
	BinaryOperation f1(&c1, c2, '+');
	BinaryOperation f2 = f1;
	f2 = f1;
	delete c2;
	return 0;
}