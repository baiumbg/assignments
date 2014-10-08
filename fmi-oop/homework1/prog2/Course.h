#pragma once

class Course
{
private:
	char* name;
	char* major;
	int year;
	int studentFlow;
	int day;
	int hour;
	int duration;
	int auditorium;
public:
	Course();
	Course(const char*, const char*, int, int, int, int, int, int);
	Course(const Course&);
	~Course();
	Course& operator=(const Course&);
	friend std::ostream& operator<<(std::ostream&, Course&);
	friend std::istream& operator>>(std::istream&, Course&);
	char* getName();
	void setName(char*);
	char* getMajor();
	void setMajor(char*);
	int getYear();
	void setYear(int);
	int getStudentFlow();
	void setStudentFlow(int);
	int getDay();
	void setDay(int);
	int getHour();
	void setHour(int);
	int getDuration();
	void setDuration(int);
	int getAuditorium();
	void setAuditorium(int);
};