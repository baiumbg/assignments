#pragma once
#include "curses.h"

struct cell{
	int coordX;
	int coordY;
	int value;
	char symbol;
};

class Minesweeper
{
private:
	cell **board;
	cell *current;
	int height;
	int width;
	int maxHeight;
	int maxWidth;
	int difficulty;
	int totalMines;
	bool gameOver;
	WINDOW *boardWin;
	void initialize();
	void setMineCount(cell*);
	void printInstructions();
	void printBoard();
	void revealMines();
	void revealNeighbours(int, int);
	bool allRevealed();
public:
	Minesweeper();
	Minesweeper(int, int, int);
	~Minesweeper();
	int start();
};