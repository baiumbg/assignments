#include <iostream>
#include "Course.h"
#include "SemesterSchedule.h"
#include "deque.h"

bool areConflicting(Course& c1, Course& c2)
{
	if(c1.getHour() >= c2.getHour() && c1.getHour() < c2.getHour() + c2.getDuration() && c1.getDay() == c2.getDay())
	{
		if(c1.getYear() == c2.getYear() && c1.getStudentFlow() == c2.getStudentFlow() && strcmp(c1.getMajor(), c2.getMajor())) return true;
		if(c1.getAuditorium() == c2.getAuditorium()) return true;
	}
	return false;
}

SemesterSchedule::SemesterSchedule()
{
	for(int i=1;i<600;i++)
	{
		auditoriums.push_back(i);
	}
}

bool SemesterSchedule::addCourse(Course& c)
{
	bool correctAuditorium = false;
	for(int i=0;i<auditoriums.size();i++)
	{
		if(c.getAuditorium() == auditoriums[i]) correctAuditorium = true;
	}
	if(!correctAuditorium)
	{
		std::cerr<<"Incorrect auditorium!\n";
		return false;
	}
	if(c.getMajor()[0] == '\0' && c.getYear() == 0 && c.getStudentFlow() == 0)
	{
		courses.push_back(c);
		return true;
	}
	for(int i=0;i<courses.size();i++)
	{
		if(areConflicting(c, courses[i]))
		{
				std::cerr<<"Course conflicting with:\n"<<courses[i];
				return false;
		}
	}
	courses.push_back(c);
	return true;
}

void SemesterSchedule::printAuditoriumSchedule(int auditorium)
{
	for(int i=1;i<7;i++)
	{
		switch(i)
		{
			case 1:
				std::cout<<"Monday:\n";
				break;
			case 2:
				std::cout<<"Tuesday:\n";
				break;
			case 3:
				std::cout<<"Wednesday:\n";
				break;
			case 4:
				std::cout<<"Thursday:\n";
				break;
			case 5:
				std::cout<<"Friday:\n";
				break;
			case 6:
				std::cout<<"Saturday:\n";
				break;
		}
		std::cout<<"---------------\n";
		for(int j=0;j<courses.size();j++)
		{
			if(courses[j].getDay() == i && courses[j].getAuditorium() == auditorium)
			{
				std::cout<<courses[j]<<"\n---------------\n";
			}
		}
	}
}

void SemesterSchedule::printClassSchedule(int studentFlow, int year, const char* major)
{
	for(int i=1;i<7;i++)
	{
		switch(i)
		{
			case 1:
				std::cout<<"Monday:\n";
				break;
			case 2:
				std::cout<<"Tuesday:\n";
				break;
			case 3:
				std::cout<<"Wednesday:\n";
				break;
			case 4:
				std::cout<<"Thursday:\n";
				break;
			case 5:
				std::cout<<"Friday:\n";
				break;
			case 6:
				std::cout<<"Saturday:\n";
				break;
		}
		std::cout<<"---------------\n";
		for(int j=0;j<courses.size();j++)
		{
			if(courses[j].getDay() == i && courses[j].getStudentFlow() == studentFlow && courses[j].getYear() == year && strcmp(courses[j].getMajor(), major) == 0)
			{
				std::cout<<courses[j]<<"\n---------------\n";
			}
		}
	}
}

bool SemesterSchedule::findFreeSlot(Course& c)
{
	for(int dayIt = 1;dayIt<7;dayIt++)
	{
		for(int hourIt = 7;hourIt<22-c.getDuration();hourIt++)
		{
			for(int courseIt = 0;courseIt<courses.size();courseIt++)
			{
				if(hasFreeSlot(dayIt, hourIt, c.getDuration(), c.getMajor(), c.getStudentFlow(), c.getYear()) || 
					(c.getYear() == 0 && c.getMajor()[0] == '\0' && c.getStudentFlow() == 0))
				{
					c.setDay(dayIt);
					c.setHour(hourIt);
					for(int auditoriumIt = 1;auditoriumIt < 600;auditoriumIt++)
					{
						if(auditoriumIsFree(hourIt, c.getDuration(), auditoriumIt))
						{
							c.setAuditorium(auditoriumIt);
							courses.push_back(c);
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool SemesterSchedule::auditoriumIsFree(int hour, int duration, int auditorium)
{
	for(int i=0;i<courses.size();i++)
	{
		if(courses[i].getAuditorium() == auditorium)
		{
			if(hour >= courses[i].getHour() && hour < courses[i].getHour() + courses[i].getDuration()) return false;
			if(hour + duration > courses[i].getHour() && hour + duration < courses[i].getHour() + courses[i].getDuration()) return false;
			if(courses[i].getHour() >= hour && courses[i].getHour() + courses[i].getDuration() <= hour + duration) return false;
		}
	}
	return true;
}

bool SemesterSchedule::hasFreeSlot(int day, int hour, int duration, const char* major, int studentFlow, int year)
{
	for(int i = 0;i<courses.size();i++)
	{
		if(courses[i].getDay() == day && courses[i].getYear() == year && courses[i].getStudentFlow() && strcmp(courses[i].getMajor(), major) == 0)
		{
			if(hour >= courses[i].getHour() && hour < courses[i].getHour() + courses[i].getDuration()) return false;
			if(hour + duration > courses[i].getHour() && hour + duration < courses[i].getHour() + courses[i].getDuration()) return false;
			if(courses[i].getHour() >= hour && courses[i].getHour() + courses[i].getDuration() <= hour + duration) return false;
		}
	}
	return true;
}