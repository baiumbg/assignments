#pragma once

class Song
{
private:
	char* name;
	char* artist;
	int yearPublished;
	int length;
	Song* original;
public:
	Song();
	Song(const Song&);
	Song(const char*, const char*, int, int, Song*);
	~Song();
	Song& operator=(const Song&);
	void setName(const char*);
	char* getName() const;
	void setArtist(const char*);
	char* getArtist() const;
	void setYearPublished(const int);
	int getYearPublished() const;
	void setLength(const int);
	int getLength() const;
	void setOriginal(Song*);
	Song* getOriginal() const;
	void print() const;
};