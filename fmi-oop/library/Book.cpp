#include "Book.h"
#include <string>

Book::Book()
{
	Author = "";
	Title = "";
	Genre = "";
	shortDesc = "";
	yearPublished = 0;
	keyWords = "";
	Rating = 0;
	ISBN = "";
}

Book::Book(std::string Author, std::string Title, std::string Genre, std::string shortDesc, int yearPublished, std::string keyWords, double Rating, std::string ISBN)
{
	setAuthor(Author);
	setTitle(Title);
	setGenre(Genre);
	setShortDesc(shortDesc);
	setYearPublished(yearPublished);
	setKeyWords(keyWords);
	setRating(Rating);
	setISBN(ISBN);
}

void Book::setAuthor(std::string Author)
{
	this->Author = Author;
}

void Book::setTitle(std::string Title)
{
	this->Title = Title;
}

void Book::setGenre(std::string Genre)
{
	this->Genre = Genre;
}

void Book::setShortDesc(std::string shortDesc)
{
	this->shortDesc = shortDesc;
}

void Book::setYearPublished(int yearPublished)
{
	this->yearPublished = yearPublished;
}

void Book::setKeyWords(std::string keyWords)
{
	this->keyWords = keyWords;
}

void Book::setRating(double Rating)
{
	this->Rating = Rating;
}

void Book::setISBN(std::string ISBN)
{
	this->ISBN = ISBN;
}

std::string Book::getAuthor()
{
	return Author;
}

std::string Book::getTitle()
{
	return Title;
}

std::string Book::getGenre()
{
	return Genre;
}

std::string Book::getShortDesc()
{
	return shortDesc;
}

int Book::getYearPublished()
{
	return yearPublished;
}

std::string Book::getKeywords()
{
	return keyWords;
}

double Book::getRating()
{
	return Rating;
}

std::string Book::getISBN()
{
	return ISBN;
}