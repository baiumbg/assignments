БЪЛГАРСКИ:

Инсталиране на библиотеката(Windows):
Разархивирайте архива и преместете:
- pdcurses.dll в MinGW/bin
- pdcurses.lib в MinGW/lib
- curses.h, panel.h в MinGW/include

Инсталиране на библиотеката(Ubuntu):
- Отворете терминала
- напишете "sudo apt-get install libncurses5-dev"

Компилиране(Windows):
- g++ driver.cpp Minesweeper.h -o minesweeper -lpdcurses

Компилиране(Ubuntu):
- g++ driver.cpp Minesweeper.h -o minesweeper -lcurses

Забележка: При пускане на играта потребителя е попитан за размер на полето и трудност на играта. Полето не може да бъде по-голямо от 30х20 (ширина х дължина) и не може да е по-малко от 4х4. Размерите трябва да бъдат въведени с интервал между тях (първо се въвежда ширина, след това дължина). Трудността на играта определя колко мини ще бъдат разпределени в полето (формула за брой мини - трудност*(РазмерНаПолето/12)). За помощ относно контролите на играта натиснете С щом стартира.

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