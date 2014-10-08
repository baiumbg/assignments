#include "Minesweeper.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Minesweeper::Minesweeper()
{
	height = 10;
	width = 10;
	difficulty = 1;
	initialize();
}

Minesweeper::Minesweeper(int width, int height, int difficulty)
{
	this -> height = height;
	this -> width = width;
	this -> difficulty = difficulty;
	initialize();
}

void Minesweeper::initialize()
{
	totalMines = ((height*width) / 12) * difficulty;
	gameOver = false;
	board = new cell* [height];
	for(int i = 0; i < height; i++)
	{
		board[i] = new cell [width];
		for(int j = 0; j < width; j++)
		{
			board[i][j].coordX = j;
			board[i][j].coordY = i;
			board[i][j].value = 0;
			board[i][j].symbol = '*';
			if(i == height / 2 && j == width / 2) current = &board[i][j];
		}
	}
	getmaxyx(stdscr, maxHeight, maxWidth);
	boardWin = newwin(height+2, 2*width+1, 0, (maxWidth-2*width-1)/2 - 1);
	srand(time(NULL));
	for(int i = 0;i < totalMines;i++)
	{
		int randCoordX = rand() % width;
		int randCoordY = rand() % height;
		if(board[randCoordY][randCoordX].value != 9)
		{
			board[randCoordY][randCoordX].value = 9;
		}
		else i--;
	}
	for(int i = 0;i < height;i++)
	{
		for(int j = 0;j < width;j++)
		{
			if(board[i][j].value != 9) setMineCount(&board[i][j]);
		}
	}
}

void Minesweeper::setMineCount(cell* currentCell)
{
	int count = 0;
	if (currentCell -> coordX > 0 && currentCell -> coordY > 0)
		if (board[currentCell -> coordY - 1][currentCell -> coordX - 1].value == 9) count++; // Top left
	if (currentCell -> coordY > 0)
		if (board[currentCell -> coordY - 1][currentCell -> coordX].value == 9) count++; // Top center
	if (currentCell -> coordX < width - 1 && currentCell -> coordY > 0)
		if (board[currentCell -> coordY - 1][currentCell -> coordX + 1].value == 9) count++; // Top right
	if (currentCell -> coordX > 0)
		if (board[currentCell -> coordY][currentCell -> coordX - 1].value == 9) count++; // Left
	if (currentCell -> coordX < width-1)
		if (board[currentCell -> coordY][currentCell -> coordX + 1].value == 9) count++; // Right
	if (currentCell -> coordX > 0 && currentCell -> coordY < height - 1)
		if (board[currentCell->coordY + 1][currentCell -> coordX - 1].value == 9) count++; // Bottom left
	if (currentCell -> coordY < height - 1)
		if (board[currentCell -> coordY + 1][currentCell -> coordX].value == 9) count++; // Bottom center
	if (currentCell -> coordX < width-1 && currentCell -> coordY < height - 1)
		if (board[currentCell -> coordY + 1][currentCell->coordX + 1].value == 9) count++; // Bottom right
	currentCell -> value = count;
}

void Minesweeper::printInstructions()
{
	attron(A_STANDOUT | A_BOLD);
	printw("Legend:");
	attroff(A_STANDOUT | A_BOLD);
	printw("\n");
	printw("* - unrevealed, ");
	attron(COLOR_PAIR(5) | A_BOLD);
	printw("P");
	attroff(COLOR_PAIR(5) | A_BOLD);
	printw(" - flagged, ");
	attron(COLOR_PAIR(3) | A_BOLD);
	printw("X");
	attroff(COLOR_PAIR(3) | A_BOLD);
	printw(" - mine, ");
	attron(COLOR_PAIR(2) | A_BOLD);
	printw("O");
	attroff(COLOR_PAIR(2) | A_BOLD);
	printw(" - flagged mine, ");
	attron(COLOR_PAIR(1));
	printw("1");
	attroff(COLOR_PAIR(1));
	printw("-");
	attron(COLOR_PAIR(8));
	printw("8");
	attroff(COLOR_PAIR(8));
	printw(" - number of mines surrounding the cell\n");
	attron(A_STANDOUT | A_BOLD);
	printw("Controls:");
	attroff(A_STANDOUT | A_BOLD);
	printw("\n");
	printw("F - flag, ESC - quit, Enter - reveal\n\n");
	printw("Press any key to return to your game...");
	refresh();
	getch();
	clear();
	printBoard();
	mvprintw(height+3, (maxWidth-25)/2, "Press C for instructions.");
	refresh();
	wrefresh(boardWin);
}

void Minesweeper::printBoard()
{
	box(boardWin, 0, 0);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int offset = 0;
			if(&board[i][j] == current) offset = 8;
			if(board[i][j].symbol > '0' && board[i][j].symbol < '9')
			{
				wattron(boardWin, COLOR_PAIR(board[i][j].value + offset));
				mvwprintw(boardWin, i + 1, 2*j+1, "%c", board[i][j].symbol);
				wattroff(boardWin, COLOR_PAIR(board[i][j].value + offset));
			}
			else if(board[i][j].symbol == 'P')
			{
				wattron(boardWin, COLOR_PAIR(5+offset) | A_BOLD);
				mvwprintw(boardWin, i + 1, 2*j + 1, "%c", board[i][j].symbol);
				wattroff(boardWin, COLOR_PAIR(5+offset) | A_BOLD);
			}
			else if(board[i][j].symbol == 'X')
			{
				wattron(boardWin, COLOR_PAIR(3+offset) | A_BOLD);
				mvwprintw(boardWin, i + 1, 2*j+1, "%c", board[i][j].symbol);
				wattroff(boardWin, COLOR_PAIR(3+offset) | A_BOLD);
			}
			else if(board[i][j].symbol == 'O')
			{
				wattron(boardWin, COLOR_PAIR(2+offset) | A_BOLD);
				mvwprintw(boardWin, i + 1, 2*j+1, "%c", board[i][j].symbol);
				wattroff(boardWin, COLOR_PAIR(2+offset) | A_BOLD);
			}
			else
			{
				if(offset) wattron(boardWin, COLOR_PAIR(15));
				mvwprintw(boardWin, i + 1, 2*j+1, "%c", board[i][j].symbol);
				if(offset) wattroff(boardWin, COLOR_PAIR(15));
			}
		}
	}
}

void Minesweeper::revealMines()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0;j < width; j++)
		{
			if (board[i][j].value == 9 && board[i][j].symbol == 'P') board[i][j].symbol = 'O';
			else if (board[i][j].value == 9) board[i][j].symbol = 'X';
		}
	}
}

void Minesweeper::revealNeighbours(int x, int y)
{
	if (x < 0 || y < 0 || x >= width || y >= height) return;
	if (board[y][x].value != 0)
	{
		board[y][x].symbol = board[y][x].value + '0';
		return;
	}
	if (board[y][x].symbol == ' ') return;
	board[y][x].symbol = ' ';
	revealNeighbours(x - 1, y);
	revealNeighbours(x + 1, y);
	revealNeighbours(x, y - 1);
	revealNeighbours(x, y + 1);
	revealNeighbours(x-1, y + 1);
	revealNeighbours(x+1, y + 1);
	revealNeighbours(x-1, y - 1);
	revealNeighbours(x+1, y - 1);
}

bool Minesweeper::allRevealed()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j].symbol == '*' && board[i][j].value != 9) return false;
            if (board[i][j].symbol == 'P' && board[i][j].value != 9) return false;
        }
    }
    return true;
}

int Minesweeper::start()
{
	initscr();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_YELLOW);
	init_pair(9, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(10, COLOR_GREEN, COLOR_WHITE);
	init_pair(11, COLOR_RED, COLOR_WHITE);
	init_pair(12, COLOR_BLUE, COLOR_WHITE);
	init_pair(13, COLOR_CYAN, COLOR_WHITE);
	init_pair(14, COLOR_YELLOW, COLOR_WHITE);
	init_pair(15, COLOR_BLACK, COLOR_WHITE);
	init_pair(16, COLOR_RED, COLOR_MAGENTA);
	printBoard();
	mvprintw(height+2, (maxWidth-25)/2, "Press C for instructions.");
	refresh();
	wrefresh(boardWin);
	while (!gameOver)
	{
		int button = getch();
		if (button == KEY_UP && current -> coordY > 0)
		{
			wclear(boardWin);
			current = &board[current -> coordY - 1][current -> coordX];
			printBoard();
			refresh();
			wrefresh(boardWin);
		}
		else if (button == KEY_DOWN && current -> coordY < height-1)
		{
			wclear(boardWin);
			current = &board[current -> coordY + 1][current -> coordX];
			printBoard();
			refresh();
			wrefresh(boardWin);
		}
		else if (button == KEY_LEFT && current -> coordX > 0)
		{
			wclear(boardWin);
			current = &board[current -> coordY][current -> coordX - 1];
			printBoard();
			refresh();
			wrefresh(boardWin);
		}
		else if (button == KEY_RIGHT && current->coordX < width - 1)
		{
			wclear(boardWin);
			current = &board[current -> coordY][current -> coordX + 1];
			printBoard();
			refresh();
			wrefresh(boardWin);
		}
		else if (button == 27)
		{
			endwin();
			return -1;
		}
		else if (button == 102)
		{
			if (board[current -> coordY][current -> coordX].symbol == '*')
			{
				wclear(boardWin);
				board[current -> coordY][current -> coordX].symbol = 'P';
				printBoard();
				refresh();
				wrefresh(boardWin);
			}
			else if (board[current -> coordY][current -> coordX].symbol == 'P')
			{
				wclear(boardWin);
				board[current -> coordY][current -> coordX].symbol = '*';
				printBoard();
				refresh();
				wrefresh(boardWin);
			}
		}
		else if (button == 99)
		{
			wclear(boardWin);
			clear();
			printInstructions();
		}
		else if ((char)button == '\n')
		{
			if (board[current -> coordY][current -> coordX].symbol == '*' || board[current -> coordY][current -> coordX].symbol == 'P')
			{
				wclear(boardWin);
				if (board[current -> coordY][current -> coordX].value == 0)
				{
					revealNeighbours(current -> coordX, current -> coordY);
					printBoard();
					refresh();
					wrefresh(boardWin);
				}
				else if (board[current -> coordY][current -> coordX].value != 9)
				{
					board[current -> coordY][current -> coordX].symbol = board[current -> coordY][current -> coordX].value + '0';
					printBoard();
					refresh();
					wrefresh(boardWin);
				}
				else
				{
					clear();
					gameOver = true;
					board[current -> coordY][current -> coordX].symbol = 'X';
					mvprintw(height+2, (maxWidth-32)/2, "Oh no! You hit a mine! You lose!");
					revealMines();
					printBoard();
					refresh();
					wrefresh(boardWin);
				}
			}
		}
		if (allRevealed())
		{
			wclear(boardWin);
			clear();
			gameOver = true;
			current = NULL;
			revealMines();
			mvprintw(height+2, (maxWidth-37)/2, "All non-mine cells revealed! You win!");
			printBoard();
			refresh();
			wrefresh(boardWin);
		}
	}
	mvprintw(height+3, (maxWidth-36)/2, "Press N for new game or Q to quit...");
	refresh();
}

Minesweeper::~Minesweeper()
{
	for(int i=0;i<height;i++)
	{
		delete[] board[i];
	}
	delete boardWin;
	std::cout<<"All done.";
}