#pragma once
#include "Book.h"
#include "User.h"
#include <vector>
#include <string>

class Library
{
private:
	std::vector<Book> *Books;
	std::vector<User> *Users;
	std::vector<std::string> *history;
	std::vector<std::string> *commandHistory;
	User *currentUser;
	std::string currentCommand;
	int currentCommandPos;
	int top;
	int bottom;
	int currY;
	int maxY;
	int maxX;
	void scrollToBot();
	void printLine(std::string);
	std::string readLine(char* prefix);
	void processCommand(std::string);
	void login();
	void logout();
	void help();
	void books();
	void printBook(int, Book);
	void users();
	void clearAll();
public:
	Library();
	~Library();
	void startConsole();
};