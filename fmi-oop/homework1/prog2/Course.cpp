#include <iostream>
#include <cstring>
#include "Course.h"

Course::Course()
{
	name = new char[2];
	name[0] = '\0';
	major = new char[2];
	major[0] = '\0';
}

Course::Course(const char* _name, const char* _major, int _year, int _studentFlow, int _day, int _hour, int _duration, int _auditorium)
{
	name = new char[strlen(_name)+1];
	strcpy(name, _name);
	major = new char[strlen(_major)+1];
	strcpy(major, _major);
	year = _year;
	studentFlow = _studentFlow;
	day = _day;
	hour = _hour;
	duration = _duration;
	auditorium = _auditorium;
}

Course::Course(const Course& other)
{
	name = new char[2];
	major = new char[2];
	*this = other;
}

Course::~Course()
{
	delete[] name;
	delete[] major;
}

Course& Course::operator=(const Course& other)
{
	setName(other.name);
	setMajor(other.major);
	year = other.year;
	studentFlow = other.studentFlow;
	day = other.day;
	hour = other.hour;
	duration = other.duration;
	auditorium = other.auditorium;
	return *this;
}

std::ostream& operator<<(std::ostream& out, Course& ob)
{
	out<<"Name: "<<ob.name<<'\n';
	out<<"Major: "<<ob.major<<'\n';
	out<<"Year: "<<ob.year<<'\n';
	out<<"Student flow: "<<ob.studentFlow<<'\n';
	out<<"Day: "<<ob.day<<'\n';
	out<<"Starts at: "<<ob.hour<<":00\n";
	out<<"Duration: "<<ob.duration<<'\n';
	out<<"Auditorium: "<<ob.auditorium;
	return out;
}

std::istream& operator>>(std::istream& in, Course& ob)
{
	in>>ob.name>>ob.major>>ob.year>>ob.studentFlow>>ob.day>>ob.hour>>ob.duration>>ob.auditorium;
	return in;
}

char* Course::getName()
{
	return name;
}

void Course::setName(char* _name)
{
	delete[] name;
	name = new char[strlen(_name)+1];
	strcpy(name, _name);
}

char* Course::getMajor()
{
	return major;
}

void Course::setMajor(char* _major)
{
	delete[] major;
	major = new char[strlen(_major)+1];
	strcpy(major, _major);
}

int Course::getYear()
{
	return year;
}

void Course::setYear(int _year)
{
	year = _year;
}

int Course::getStudentFlow()
{
	return studentFlow;
}

void Course::setStudentFlow(int _studentFlow)
{
	studentFlow = _studentFlow;
}

int Course::getDay()
{
	return day;
}

void Course::setDay(int _day)
{
	day = _day;
}

int Course::getHour()
{
	return hour;
}

void Course::setHour(int _hour)
{
	hour = _hour;
}

int Course::getDuration()
{
	return duration;
}

void Course::setDuration(int _duration)
{
	duration = _duration;
}

int Course::getAuditorium()
{
	return auditorium;
}

void Course::setAuditorium(int _auditorium)
{
	auditorium = _auditorium;
}