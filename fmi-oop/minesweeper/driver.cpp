#include "Minesweeper.h"

int main()
{
	initscr();
	int key = 0;
	while((char)key != 'q' && (char)key != 'Q')
	{
		clear();
		int difficulty, width, height;
		mvprintw(2, 0, "Must be entered on a single line seperated by a space.");
		mvprintw(3, 0, "Maximum dimensions: 4<=width<=30; 4<=height<=20");
		mvprintw(0, 0, "Enter width and height: ");
		refresh();
		scanw("%d %d", &width, &height);
		refresh();
		while (width < 4 || height < 4 || width>30 || height>20)
		{
			clear();
			printw("Width/height over/under maximum dimensions. Enter new values: ");
			refresh();
			scanw("%d %d", &width, &height);
		}
		clear();
		printw("Enter difficulty(1-4): ");
		refresh();
		scanw("%d", &difficulty);
		while (difficulty < 1 || difficulty > 4)
		{
			clear();
			printw("Difficulty must be between 1 and 4! Enter a new value: ");
			refresh();
			scanw("%d", &difficulty);
		}
		clear();
		refresh();
		Minesweeper *game = new Minesweeper(width, height, difficulty);
		endwin();
		if(game -> start() == -1) return 0;
		key = getch();
		while((char)key != 'q' && (char)key != 'Q' && (char)key != 'N' && (char)key != 'n') key = getch();
		curs_set(1);
		echo();
	}
	endwin();
	return 0;
}