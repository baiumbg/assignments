#include <iostream>
#include "string.h"
using namespace std;

int main()
{
	String test = "abcdef";
	String test2 = "agcde";
	test = test2;
	cout<<test;
	return 0;
}