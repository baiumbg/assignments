#include "Library.h"
#include "Book.h"
#include "User.h"
#include "functions.cpp"
#include <curses.h>
#include <vector>
#include <string>
#include <fstream>

void Library::scrollToBot()
{
	clear();
	top = currY-maxY;
	bottom = currY;
	for(int i = currY-maxY; i < currY; i++)
	{
		printw("%s", history->at(i).c_str());
	}
	refresh();
	curs_set(1);
}
void Library::printLine(std::string line = "")
{
	std::vector<std::string> lines;
	lines = split(line);
	for(int i = 0; i < lines.size(); i++)
	{
		printw("%s", (lines.at(i) + "\n").c_str());
		history->push_back(lines.at(i) + "\n");
		bottom++;
		currY++;
		if(bottom > maxY) top++;
	}
	refresh();
}
std::string Library::readLine(char* prefix)
{
	std::string prefixString = std::string(prefix);
	bool atBot = true;
	std::string line;
	std::vector<std::string> lines;
	lines = split(prefix);
	for(int i = 0; i < lines.size()-1; i++)
	{
		printw("%s", (lines.at(i) + "\n").c_str());
		history->push_back(lines.at(i) + "\n");
		bottom++;
		currY++;
		if(bottom > maxY) top++;
	}
	printw("%s", lines.at(lines.size()-1).c_str());
	int y, x;
	int c = 0;
	while(c != '\n')
	{
		c = getch();
		getyx(stdscr, y, x);
		if(c == KEY_PPAGE)
		{
			if(top >= 0 && currY > maxY)
			{
				if(atBot)
				{
					scrl(-2);
					mvprintw(0, 0, "%s%s", history->at(top+1).c_str(), history->at(top).c_str());
					top-=2;
					bottom-=2;

				}
				else
				{
					scrl(-1);
					mvprintw(0, 0, "%s", history->at(top).c_str());
					top--;
					bottom--;
				}
				curs_set(0);
				atBot = false;
				refresh();
			}
		}
		else if(c == KEY_NPAGE)
		{
			if(bottom < currY-1)
			{
				top++;
				bottom++;
				mvprintw(maxY-1, 0, "%s", history->at(bottom-1).c_str());
				refresh();
			}
			if(bottom == currY-1 && !atBot)
			{
				top++;
				bottom++;
				curs_set(1);
				atBot = true;
				scrl(1);
				if(prefixString!= "Password: ") mvprintw(maxY-1, 0, "%s%s", lines.at(lines.size()-1).c_str(), line.c_str());
				else mvprintw(maxY-1, 0, "Password: %s", std::string(line.length(), '*').c_str());
				refresh();
			}
		}
		else if(c == KEY_UP && currentCommandPos > 0 && prefixString == "> ")
		{
			move(y, 2);
			clrtoeol();
			printw(commandHistory->at(--currentCommandPos).c_str());
			refresh();
			line = commandHistory->at(currentCommandPos);
		}
		else if(c == KEY_DOWN && currentCommandPos < commandHistory->size() && prefixString == "> ")
		{
			move(y, 2);
			clrtoeol();
			if(currentCommandPos == commandHistory->size()-1)
			{
				line = "";
				currentCommandPos++;
			}
			else
			{
				printw(commandHistory->at(++currentCommandPos).c_str());
				line = commandHistory->at(currentCommandPos);
			}
			refresh();
		}
		else if(c == KEY_LEFT && x > prefixString.length())
		{
			move(y, x-1);
		}
		else if(c == KEY_RIGHT && x < prefixString.length() + line.length())
		{
			move(y, x+1);
		}
		else if(c == KEY_BACKSPACE || c == 8)
		{
			if(line.length() > 0 && atBot) {
				line.erase(line.begin() + x - prefixString.length() - 1);
				move(y, x - 1);
				delch();
				refresh();
			}
		}
		else if(c == KEY_DC)
		{
			if(x < line.length() + prefixString.length())
			{
				line.erase(line.begin() + x - prefixString.length());
				delch();
				refresh();
			}
		}
		else if(c == KEY_HOME)
		{
			move(y, prefixString.length());
		}
		else if(c == KEY_END)
		{
			move(y, prefixString.length() + line.length());
		}
		else if(isChar(c))
		{
			if(!atBot)
			{
				scrollToBot();
				atBot = true;
				printw("%s%s", prefix, line.c_str());
				getyx(stdscr, y, x);
			}
			line.insert(line.begin() + (x - prefixString.length()), (char)c);
			if(prefixString!= "Password: ") addstr(((char)c + line.substr(x - prefixString.length() + 1)).c_str());
			else addstr(std::string(line.length() + prefixString.length() - x, '*').c_str());
			move(y, x+1);
			refresh();
		}
		//c = getch();
	}
	if(!atBot)
	{
		scrollToBot();
		atBot = true;
		printw("%s%s\n", prefix, line.c_str());
		getyx(stdscr, y, x);
	}
	else mvprintw(y, prefixString.length() + line.length(), "\n");
	refresh();
	if(prefixString!= "Password: ") history->push_back(lines.at(lines.size()-1) + line + "\n");
	else history->push_back(prefixString+ std::string(line.length(), '*') + "\n");
	if(bottom > maxY) top++;
	bottom++;
	currY++;
	return line;
}
void Library::processCommand(std::string command)
{
	currentCommand = command;
	std::vector<std::string> args;
	explode(args, command, ' ');
	if(args.at(0) == "login")
	{
		if(args.size() == 1)
		{
			if(currentUser == NULL) login();
			else
			{
				printLine("User already logged in.");
				printLine();
			}
		}
		else
		{
			printLine("Incorrect command syntax. Type \"help login\" for more info.");
			printLine();
		}
	}
	else if(args.at(0) == "logout")
	{
		if(args.size() == 1) {
			if(currentUser != NULL) logout();
			else
			{
				printLine("Command requires login.");
				printLine();
			}
		}
		else
		{
			printLine("Incorrect command syntax. Type \"help logout\" for more info.");
			printLine();
		}
	}
	else if(args.at(0) == "help")
	{
		help();
	}
	else if(args.at(0) == "books")
	{
		if(currentUser != NULL) books();
		else
		{
			printLine("Command requires login.");
			printLine();
		}
	}
	else if(args.at(0) == "users")
	{
		if(currentUser != NULL)
		{
			if(currentUser->isAdmin()) users();
			else
			{
				printLine("Access denied. Command requires administrative privileges.");
				printLine();
			}
		}
		else
		{
			printLine("Command requires login.");
			printLine();
		}
	}
	else if(args.at(0) == "clear")
	{
		clearAll();
	}
	else if(args.at(0) != "exit")
	{
		printLine("Command not recognized. Type \"help\" for more info on commands.");
		printLine();
	}
}
void Library::login()
{
	std::string username = readLine("Username: ");
	std::string password = readLine("Password: ");
	printLine();
	for(int i = 0; i < Users->size(); i++)
	{
		if(Users->at(i).getUsername() == username)
		{
			if(Users->at(i).getPassword() == password)
			{
				currentUser = new User(username, password, Users->at(i).isAdmin());
				printLine("Welcome, " + currentUser->getUsername() + "!");
			}
			else
			{
				printLine("Incorrect password.");
			}
			printLine();
			return;
		}
	}
	printLine("No user called '" + username + "'.");
	printLine();
}
void Library::logout()
{
	std::string user = currentUser->getUsername();
	currentUser = NULL;
	printLine("User " + user + " logged out.");
	printLine();
}
void Library::help()
{
	std::vector<std::string> args;
	int numArgs = explode(args, currentCommand, ' ');
	if(numArgs == 1)
	{
		printLine("    help [option]");
		printLine("        Prints a help message for a specified command. If a command has not been specified displays this help message.");
		printLine("    login");
		printLine("        User is prompted for username and password in order to gain access to more functions.");
		printLine("    logout");
		printLine("        User is logged out.");
		printLine("    books <option> <option> [option]");
		printLine("        Prints information about books and manipulates the database. Type \"help books\" for more info.");
		printLine("    users <option> <option>");
		printLine("        Manipulates the user database. Type \"help users\" for more info.");
		printLine("    clear");
		printLine("        Clears the screen.");
		printLine("    exit");
		printLine("        Saves any changes made to books/users and terminates the program. DO NOT USE THE X BUTTON TO EXIT.");
	}
	else if(numArgs == 2)
	{
		if(args.at(1) == "help")
		{
			printLine("    help [command]");
			printLine("        Displays help about a specific command if provided. If not, displays the default help message.");
		}
		else if(args.at(1) == "login")
		{
			printLine("    login");
			printLine("        User is prompted for username and password in order to gain access to more functions.");
		}
		else if(args.at(1) == "logout")
		{
			printLine("    logout");
			printLine("        User is logged out. Requires login.");
		}
		else if(args.at(1) == "books")
		{
			printLine("    books <all | info| find | sort | add | remove> <option> [option_std::string]");
			printLine();
			printLine("        books all");
			printLine("            Displays short info about all books in the database.");
			printLine("        books info <isbn_value>");
			printLine("            Displays all information about a specific book.");
			printLine("        books find <title | author | tag> <text_to_search>");
			printLine("            Displays all information about every book fitting the criteria.");
			printLine("        books sort <year | rating> [asc | desc]");
			printLine("            Sorts all books by year/rating. Default sort mode is ascending.");
			printLine("        books add");
			printLine("            User is prompted for book properties. The book is then added to the database. Requires administrative privileges.");
			printLine("        books remove <isbn_value>");
			printLine("            Removes the specified book from the database. Requires administrative privileges.");
			printLine();
			printLine("    Requires user to be logged in.");
		}
		else if(args.at(1) == "users")
		{
			printLine("    users <add | remove | promote> <option>");
			printLine();
			printLine("        users add");
			printLine("            User is prompted for a username and password, which are then added to the database.");
			printLine("        users remove <username>");
			printLine("            Specified user is removed from the database.");
			printLine("        users promote <username>");
			printLine("            Specified user is given administrative privileges.");
			printLine("        users demote <username>");
			printLine("            Removes the specified user's administrative privileges;");
			printLine();
			printLine("    Requires user to be logged in and have administrative privileges.");
		}
		else if(args.at(1) == "clear")
		{
			printLine("    clear");
			printLine("        Clears the screen.");
		}
		else if(args.at(1) == "exit")
		{
			printLine("    exit");
			printLine("        Saves any changes made to books/users and terminates the program. DO NOT USE THE X BUTTON TO EXIT.");
		}
		else printLine("Command '"+ args.at(1) +"' not recognized.");
	}
	else printLine("Incorrect command syntax. Type \"help help\" for more info.");
	printLine();
}
void Library::books()
{
	std::vector<std::string> args;
	int numArgs = explode(args, currentCommand, ' ');
	if(numArgs > 1)
	{
		if(args.at(1) == "all")
		{
			if(!Books->empty())
			{
				for(int i = 0;i < Books->size()-1; i++)
				{
					printBook(1, Books->at(i));
					printLine("--------------");
				}
				printBook(1, Books->at(Books->size()-1));
			}
			else
			{
				printLine("No books currently in database.");
			}
		}
		else if(args.at(1) == "info")
		{
			if(numArgs == 3)
			{
				for(int i = 0; i<Books->size(); i++)
				{
					if(Books->at(i).getISBN() == args.at(2))
					{
						printBook(2, Books->at(i));
						printLine();
						return;
					}
				}
				printLine("No book with ISBN '" + args.at(2) + "' found.");
			}
			else if(numArgs < 3)
			{
				printLine("Missing command arguments. Type \"help books\" for more info.");
			}
			else
			{
				printLine("Incorrect command syntax. Type \"help books\" for more info.");
			}
		}
		else if(args.at(1) == "find")
		{
			if(numArgs == 4)
			{
				if(args.at(2) == "title" || args.at(2) == "author" || args.at(2) == "tag")
				{
					if(!Books->empty())
					{
						std::string key = "";
						for(int i = 4; i < args.size(); i++)
						{
							key = key + " " + args.at(i);
						}
						for(int i = 0; i < Books->size(); i++)
						{
							if(args.at(2) == "title" && stringContains(key, Books->at(i).getTitle()))
							{
								printBook(2, Books->at(i));
							}
							else if(args.at(2) == "author" && stringContains(key, Books->at(i).getAuthor()))
							{
								printBook(2, Books->at(i));
							}
							else if(args.at(2) == "tag" && stringContains(key, Books->at(i).getKeywords()))
							{
								printBook(2, Books->at(i));
							}
						}
					}
					else
					{
						printLine("No books currently in database.");
					}
				}
				else
				{
					printLine("Incorrect command syntax. Type \"help books\" for more info.");
				}
			}
			else if(numArgs < 4)
			{
				printLine("Missing command arguments. Type \"help books\" for more info.");
			}
			else
			{
				printLine("Incorrect command syntax. Type \"help books\" for more info.");
			}
		}
		else if(args.at(1) == "sort")
		{
			if(numArgs == 3 || numArgs == 4)
			{
				if(args.at(2) == "year" || args.at(2) == "rating")
				{
					if(!Books->empty())
					{
						std::vector<Book> *tempBooks = new std::vector<Book>;
						for(int i = 0; i < Books->size(); i++)
						{
							tempBooks->push_back(Books->at(i));
						}
						if(args.at(2) == "year")
						{
							for(int i = 0; i < Books->size(); i++)
							{
								for(int j = i+1; j < Books->size(); j++)
								{
									if(numArgs == 4 && args.at(3) == "desc" && tempBooks->at(i).getYearPublished() < tempBooks->at(j).getYearPublished()) std::swap(tempBooks->at(i), tempBooks->at(j));
									else if(tempBooks->at(i).getYearPublished() > tempBooks->at(j).getYearPublished()) std::swap(tempBooks->at(i), tempBooks->at(j));
								}
							}
						}
						else
						{
							for(int i = 0; i < tempBooks->size(); i++)
							{
								for(int j = i+1; j < Books->size(); j++)
								{
									if(numArgs == 4 && args.at(3) == "desc" && tempBooks->at(i).getRating() < tempBooks->at(j).getRating()) std::swap(tempBooks->at(i), tempBooks->at(j));
									else if(tempBooks->at(i).getRating() > tempBooks->at(j).getRating()) std::swap(tempBooks->at(i), tempBooks->at(j));
								}
							}
						}
						for(int i = 0; i < tempBooks->size()-1; i++)
						{
							printBook(2, tempBooks->at(i));
							printLine("--------------");
						}
						printBook(2, tempBooks->at(tempBooks->size()-1));
						delete tempBooks;
					}
					else
					{
						printLine("No books currently in database.");
					}
				}
				else
				{
					printLine("Incorrect command syntax. Type \"help books\" for more info.");
					printLine();
				}
			}
			else if(numArgs < 3)
			{
				printLine("Missing command arguments. Type \"help books\" for more info.");
			}
			else
			{
				printLine("Incorrect command syntax. Type \"help books\" for more info.");
			}
		}
		else if(args.at(1) == "add")
		{
			if(currentUser->isAdmin())
			{
				if(numArgs == 2)
				{
					Book tempBook;
					tempBook.setTitle(readLine("Title: "));
					tempBook.setAuthor(readLine("Author: "));
					tempBook.setGenre(readLine("Genre: "));
					tempBook.setShortDesc(readLine("Description: "));
					tempBook.setYearPublished(atoi(readLine("Year: ").c_str()));
					tempBook.setKeyWords(readLine("Keywords: "));
					tempBook.setRating(atof(readLine("Rating: ").c_str()));
					tempBook.setISBN(readLine("ISBN: "));
					printLine();
					std::string keep = readLine("Are you sure you want to add the above book to the database? <Y | N>: ");
					if(keep == "Y" || keep == "y")
					{
						Books->push_back(tempBook);
						printLine("Book added to database.");
					}
					else
					{
						printLine("Book discarded.");
					}
				}
				else
				{
					printLine("Incorrect command syntax. Type \"help books\" for more info.");
				}
			}
			else
			{
				printLine("Access denied. Command requires administrative privileges.");
			}
		}
		else if(args.at(1) == "remove")
		{
			if(currentUser->isAdmin())
			{
				if(numArgs == 3)
				{
					for(int i = 0; i < Books->size(); i++)
					{
						if(Books->at(i).getISBN() == args.at(2))
						{
							Books->erase(Books->begin()+i);
							printLine("Book removed successfully.");
							printLine();
							return;
						}
					}
					printLine("No book with ISBN '" + args.at(2) + "' found.");
				}
				else if(numArgs < 3)
				{
					printLine("Missing command arguments. Type \"help books\" for more info.");
				}
				else
				{
					printLine("Incorrect command syntax. Type \"help books\" for more info.");
				}
			}
			else
			{
				printLine("Access denied. Command requires administrative privileges.");
			}
		}
		else
		{
			printLine("Incorrect command syntax. Type \"help books\" for more info.");
		}
	}
	else printLine("Missing command arguments. Type \"help books\" to view syntax.");
	printLine();
}
void Library::printBook(int mode, Book b)
{
	if(mode == 1)
	{
		printLine("Title: " + b.getTitle());
		printLine("Author: " + b.getAuthor());
		printLine("Genre: " + b.getGenre());
		printLine("ISBN: " + b.getISBN());
	}
	else if(mode == 2)
	{
		printLine("Title: " + b.getTitle());
		printLine("Author: " + b.getAuthor());
		printLine("Genre: " + b.getGenre());
		printLine("Description: " + b.getShortDesc());
		printLine("Year: " + intToString(b.getYearPublished()));
		printLine("Keywords: " + b.getKeywords());
		printLine("Rating: " + doubleToString(b.getRating()));
		printLine("ISBN: " + b.getISBN());
	}
}
void Library::users()
{
	std::vector<std::string> args;
	int numArgs = explode(args, currentCommand, ' ');
	if(numArgs > 1)
	{
		if(args.at(1) == "all")
		{
			for(int i = 0; i < Users->size()-1; i++)
			{
				printLine("Username: " + Users->at(i).getUsername());
				printLine("Password: " + Users->at(i).getPassword());
				if(Users->at(i).isAdmin()) printLine("Admin: Yes");
				else printLine("Admin: No");
				printLine("--------------");
			}
			printLine("Username: " + Users->back().getUsername());
			printLine("Password: " + Users->back().getPassword());
			if(Users->back().isAdmin()) printLine("Admin: Yes");
			else printLine("Admin: No");
		}
		else if(args.at(1) == "add")
		{
			if(numArgs == 2)
			{
				std::string username = readLine("Username: ");
				std::string password = readLine("Password: ");
				User newUser(username, password);
				Users->push_back(newUser);
				printLine("User '"+ username +"' added.");
			}
			else printLine("Incorrect command syntax. Type \"help users\" for more info.");
		}
		else if(args.at(1) == "remove")
		{
			if(numArgs == 3)
			{
				for(int i = 0; i < Users->size(); i++)
				{
					if(Users->at(i).getUsername() == args.at(2))
					{
						Users->erase(Users->begin()+i);
						printLine("User '"+ args.at(2) +"' removed.");
						printLine();
						return;
					}
				}
				printLine("No user called '" + args.at(1) + "' found.");
			}
			else if(numArgs < 3) printLine("Missing command arguments. Type \"help users\" for more info.");
			else printLine("Incorrect command syntax. Type \"help users\" for more info.");
		}
		else if(args.at(1) == "promote")
		{
			if(numArgs == 3)
			{
				for(int i = 0; i < Users->size(); i++)
				{
					if(Users->at(i).getUsername() == args.at(2))
					{
						if(Users->at(i).isAdmin()) printLine("User '" + args.at(2) + "' already has administrative privileges.");
						else
						{
							Users->at(i).promote();
							printLine("User '" + args.at(2) + "' granted administrative privileges.");
						}
						printLine();
						return;
					}
				}
			}
			else if(numArgs < 3) printLine("Missing command arguments. Type \"help users\" for more info.");
			else printLine("Incorrect command syntax. Type \"help users\" for more info.");
		}
		else if(args.at(1) == "demote")
		{
			if(numArgs == 3)
			{
				for(int i = 0; i < Users->size(); i++)
				{
					if(Users->at(i).getUsername() == args.at(2))
					{
						if(!Users->at(i).isAdmin()) printLine("User '" + args.at(2) + "' doesn't have administrative privileges.");
						else
						{
							Users->at(i).demote();
							printLine("User '" + args.at(2) + "' stripped of administrative privileges.");
						}
						printLine();
						return;
					}
				}
			}
			else if(numArgs < 3) printLine("Missing command arguments. Type \"help users\" for more info.");
			else printLine("Incorrect command syntax. Type \"help users\" for more info.");
		}
		else printLine("Incorrect command syntax. Type \"help users\" for more info.");
	}
	else printLine("Missing command arguments. Type \"help users\" for more info.");
	printLine();
}
void Library::clearAll()
{
	delete history;
	history = new std::vector<std::string>;
	clear();
	refresh();
	bottom = 0;
	top = 0;
	currY = 0;
}

Library::Library()
{
	Users = new std::vector<User>;
	Books = new std::vector<Book>;
	history = new std::vector<std::string>;
	commandHistory = new std::vector<std::string>;
	currentUser = NULL;
	top = 0;
	bottom = 0;
	currY = 0;
	currentCommandPos = 0;
	std::fstream file;
	file.open("users.txt", std::fstream::in);
	std::string line;
	while(getline(file, line))
	{
		std::vector<std::string> details;
		explode(details, line, ':');
		User temp(details);
		Users->push_back(temp);
	}
	file.close();
	file.open("books.txt", std::fstream::in);
	int i=0;
	Book temp;
	while(getline(file, line))
	{
		switch(i%8) {
			case 0:
				temp.setAuthor(line);
				break;
			case 1:
				temp.setTitle(line);
				break;
			case 2:
				temp.setGenre(line);
				break;
			case 3:
				temp.setShortDesc(line);
				break;
			case 4:
				temp.setYearPublished(atoi(line.c_str()));
				break;
			case 5:
				temp.setKeyWords(line);
				break;
			case 6:
				temp.setRating(atof(line.c_str()));
				break;
			case 7:
				temp.setISBN(line);
				Books->push_back(temp);
				break;
		}
		i++;
	}
	file.close();
}
void Library::startConsole()
{
	initscr();
	scrollok(stdscr, true);
	noecho();
	keypad(stdscr, true);
	getmaxyx(stdscr, maxY, maxX);
	std::string command = "";
	while(command != "exit")
	{
		command = readLine("> ");
		printLine();
		if(command.length() > 0)
		{
			commandHistory->push_back(command);
			currentCommandPos = commandHistory->size();
			processCommand(command);
		}
	}
	printLine("Press any key to exit...");
	getch();
	endwin();
}
Library::~Library()
{
	std::fstream file;
	file.open("books.txt", std::fstream::out | std::fstream::trunc);
	for(int i = 0; i < Books->size(); i++)
	{
		file << Books->at(i).getAuthor() << std::endl;
		file << Books->at(i).getTitle() << std::endl;
		file << Books->at(i).getGenre() << std::endl;
		file << Books->at(i).getShortDesc() << std::endl;
		file << Books->at(i).getYearPublished() << std::endl;
		file << Books->at(i).getKeywords() << std::endl;
		file << Books->at(i).getRating() << std::endl;
		file << Books->at(i).getISBN() << std::endl;
	}
	file.close();
	file.open("users.txt", std::fstream::out | std::fstream::trunc);
	for(int i = 0; i < Users->size(); i++)
	{
		file << Users -> at(i).getUsername() << ':';
		file << Users -> at(i).getPassword() << ':';
		if(Users->at(i).isAdmin()) file << "true" << std::endl;
		else file << "false" << std::endl;
	}
	file.close();
	delete Users;
	delete Books;
	delete currentUser;
	delete history;
	delete commandHistory;
}