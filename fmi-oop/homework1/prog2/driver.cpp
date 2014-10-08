#include <iostream>
#include "SemesterSchedule.h"
using namespace std;

int main()
{
	SemesterSchedule informatika;
	Course c1("Algebra-practicum", "Informatics", 1, 1, 1, 11, 3, 307);
	Course c2("Calculus", "Informatics", 1, 1, 1, 14, 2, 101);
	Course c3("Algebra", "Informatics", 1, 1, 2, 10, 3, 101);
	Course c4("Calculus", "Informatics", 1, 1, 2, 13, 2, 101);
	Course c5("Object-oriented Programming-practicum", "Informatics", 1, 1, 2, 15, 2, 303);
	Course c6("Object-oriented Programming-practicum", "Informatics", 1, 1, 3, 10, 2, 319);
	Course c7("Calculus-practicum", "Informatics", 1, 1, 3, 13, 2, 4);
	Course c8("Object-oriented Programming", "Informatics", 1, 1, 3, 15, 3, 101);
	Course c9("Calculus-practicum", "Informatics", 1, 1, 4, 10, 2, 310);
	Course c10("Discrete Mathematics-practicum", "Informatics", 1, 1, 4, 12, 3, 101);
	Course c11("Discrete Mathematics", "Informatics", 1, 1, 4, 15, 3, 101);
	informatika.addCourse(c1);
	informatika.addCourse(c2);
	informatika.addCourse(c3);
	informatika.addCourse(c4);
	informatika.addCourse(c5);
	informatika.addCourse(c6);
	informatika.addCourse(c7);
	informatika.addCourse(c8);
	informatika.addCourse(c9);
	informatika.addCourse(c10);
	informatika.addCourse(c11);
	informatika.printClassSchedule(1, 1, "Informatics");
	return 0;
}