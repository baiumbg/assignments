#include <iostream>
#include <cstring>
#include "Song.h"
#include "Album.h"
#include "deque.h"

Album::Album()
{
	name = new char[100];
}

Album::Album(const Album& other)
{
	songs = other.getSongs();
	name = new char[strlen(other.getName())+1];
	strcpy(name, other.getName());
}

Album::~Album()
{
	delete[] name;
}

Album& Album::operator=(const Album& other)
{
	setName(other.getName());
	songs = other.getSongs();
	return *this;
}

void Album::setName(const char* _name)
{
	delete[] name;
	name = new char[strlen(_name)+1];
	strcpy(name, _name);
}

char* Album::getName() const
{
	return name;
}

void Album::setSongs(deque<Song> _songs)
{
	songs = _songs;
}

deque<Song> Album::getSongs() const
{
	return songs;
}

void Album::addSong(Song song)
{
	songs.push_back(song);
}

void Album::print()
{
	std::cout<<"Album name: "<<name<<"\nAlbum artist: "<<getArtist()<<"\n\nSongs:\n\n";
	for(int i = 0; i<songs.size(); i++)
	{
		songs[i].print();
	}
	std::cout<<"Album length: "<<getLength()<<'\n';
}

int Album::getLength()
{
	int length = 0;
	for(int i = 0; i<songs.size(); i++)
	{
		length+=songs[i].getLength();
	}
	return length;
}

const char* Album::getArtist()
{
	const char* artist = songs.front().getArtist();
	for(int i = 0; i<songs.size(); i++)
	{
		if(strcmp(artist, songs[i].getArtist()) != 0) 
		{
			return "Various artists";
		}
	}
	return artist;
}

Song* Album::findSong(char* songName)
{
	for(int i = 0; i<songs.size(); i++)
	{
		if(strcmp(songName, songs[i].getName()) == 0) return &songs[i];
	}
	return NULL;
}

void Album::deleteDuplicates()
{
	for(int i = 0; i<songs.size(); i++)
	{
		for(int j = i+1; j<songs.size(); j++)
		{
			if(strcmp(songs[i].getName(), songs[j].getName()) == 0 && strcmp(songs[i].getArtist(), songs[j].getArtist()) == 0 && 
			   songs[i].getYearPublished() == songs[j].getYearPublished() && songs[i].getLength() == songs[j].getLength())
			{
				songs.removeAt(j);
			}
		}
	}
}

void Album::detectCovers()
{
	for(int i = 0; i<songs.size(); i++)
	{
		for(int j = i+1; j<songs.size(); j++)
		{
			if(strcmp(songs[i].getName(), songs[j].getName()) == 0 && strcmp(songs[i].getArtist(), songs[j].getArtist()) != 0)
			{
				if(songs[i].getYearPublished()<=songs[j].getYearPublished())
				{
					songs[j].setOriginal(&songs[i]);
				}
				else
				{
					songs[i].setOriginal(&songs[j]);
				}
			}
		}
	}
}