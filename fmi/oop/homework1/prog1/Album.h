#pragma once
#include "deque.h"

class Album
{
private:
	deque<Song> songs;
	char* name;
public:
	Album();
	Album(const Album&);
	~Album();
	Album& operator=(const Album&);
	void setSongs(deque<Song>);
	deque<Song> getSongs() const;
	void setName(const char*);
	char* getName() const;
	void addSong(Song);
	void print();
	int getLength();
	const char* getArtist();
	Song* findSong(char*);
	void deleteDuplicates();
	void detectCovers();
};