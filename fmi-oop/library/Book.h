#pragma once
#include <string>

class Book
{
private:
	std::string Author;
	std::string Title;
	std::string Genre;
	std::string shortDesc;
	int yearPublished;
	std::string keyWords;
	double Rating;
	std::string ISBN;
public:
	Book();
	Book(std::string, std::string, std::string, std::string, int, std::string, double, std::string);
	void setAuthor(std::string Author);
	void setTitle(std::string);
	void setGenre(std::string);
	void setShortDesc(std::string);
	void setYearPublished(int);
	void setKeyWords(std::string);
	void setRating(double);
	void setISBN(std::string);
	std::string getAuthor();
	std::string getTitle();
	std::string getGenre();
	std::string getShortDesc();
	int getYearPublished();
	std::string getKeywords();
	double getRating();
	std::string getISBN();
};