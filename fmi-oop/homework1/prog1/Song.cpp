#include <iostream>
#include <cstring>
#include "Song.h"

Song::Song()
{
	name = new char[100];
	artist = new char[100];
	original = NULL;
}

Song::Song(const Song& other)
{
	name = new char[100];
	artist = new char[100];
	*this = other;
}

Song::Song(const char* _name, const char* _artist, int _yearPublished, int _length, Song* _original)
{
	name = new char[100];
	artist = new char[100];
	setName(_name);
	setArtist(_artist);
	setYearPublished(_yearPublished);
	setLength(_length);
	setOriginal(_original);
}

Song::~Song()
{
	delete[] name;
	delete[] artist;
}

Song& Song::operator=(const Song &other)
{
	setName(other.getName());
	setArtist(other.getArtist());
	setYearPublished(other.getYearPublished());
	setLength(other.getLength());
	setOriginal(other.getOriginal());
	return *this;
}

void Song::setName(const char* _name)
{
	delete[] name;
	name = new char[strlen(_name)+1];
	strcpy(name, _name);
}

char* Song::getName() const
{
	return name;
}

void Song::setArtist(const char* _artist)
{
	delete[] artist;
	artist = new char[strlen(_artist)+1];
	strcpy(artist, _artist);
}

char* Song::getArtist() const
{
	return artist;
}

void Song::setYearPublished(const int _yearPublished)
{
	yearPublished = _yearPublished;
}

int Song::getYearPublished() const
{
	return yearPublished;
}

void Song::setLength(const int _length)
{
	length = _length;
}

int Song::getLength() const
{
	return length;
}

void Song::setOriginal(Song* _original)
{
	original = _original;
}

Song* Song::getOriginal() const
{
	return original;
}

void Song::print() const
{
	std::cout<<"Name: "<<name<<"\nArtist: "<<artist<<"\nYear Published: "<<yearPublished<<"\nLength: "<<length<<'\n';
	if(original!=NULL)
	{
		std::cout<<"Original:\n---------------\n";
		original->print();
		std::cout<<"---------------\n";
	}
	std::cout<<'\n';
}