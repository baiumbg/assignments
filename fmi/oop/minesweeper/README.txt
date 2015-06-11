БЪЛГАРСКИ:

Инсталация на PDCurses(Windows):
Разархивирайте архива и преместете:
- pdcurses.dll в MinGW/bin
- pdcurses.lib в MinGW/lib
- curses.h, panel.h в MinGW/include

Инсталация на PDCurses(Ubuntu):
- отворете Терминала
- изпълнете "sudo apt-get install libncurses5-dev"

Компилация(Windows):
- g++ driver.cpp Minesweeper.h -o minesweeper -lpdcurses

Компилация(Ubuntu):
- g++ driver.cpp Minesweeper.h -o minesweeper -lcurses

Забележка: Като стартирате играта се пита за големината на полето и трудността на играта. Големината не може да надминава 30x20 (ширина х височина) и не може да бъде по-малка от 4х4. Ширината и големината трябва да бъдат въведени със space между тях (първо ширина, след това височина). Трудността на играта определя колко минички ще бъдат сложени из полето (формула за брой - трудност*(големина на полето / 12)). За повече информация, натиснете С като започнете игра.
ENGLISH:

PDCurses installation(Windows):
Extract the archive and move:
- pdcurses.dll to MinGW/bin
- pdcurses.lib to MinGW/lib
- curses.h, panel.h to MinGW/include

PDCurses installation(Ubuntu):
- open Terminal
- type "sudo apt-get install libncurses5-dev"

Compilation(Windows):
- g++ driver.cpp Minesweeper.h -o minesweeper -lpdcurses

Compilation(Linux):
- g++ driver.cpp Minesweeper.h -o minesweeper -lcurses

Note: Upon game startup the user is prompted for the game field's size and the difficulty of the game. The size cannot be larger than 30x20 (width x height) and cannot be smaller than 4x4. The width and height must be entered with a space between them (first width, then height). The difficulty of the game decides how many mines will be placed on the field (formula - difficulty*(FieldSize/12)). For more info on controls press C when the game has started.
