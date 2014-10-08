#pragma once
#include "deque.h"
#include "Course.h"

class SemesterSchedule
{
private:
	deque<Course> courses;
	deque<int> auditoriums;
public:
	SemesterSchedule();
	bool addCourse(Course&);
	void printAuditoriumSchedule(int);
	void printClassSchedule(int, int, const char*);
	bool findFreeSlot(Course&);
	bool auditoriumIsFree(int, int, int);
	bool hasFreeSlot(int, int, int, const char*, int, int);
};