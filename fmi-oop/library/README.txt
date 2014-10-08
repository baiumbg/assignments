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
- g++ test.cpp Book.h User.h Library.h -o test -lpdcurses

Компилиране(Ubuntu):
- g++ test.cpp Book.h User.h Library.h -o test -lcurses

Забележка: С командата "help" се извеждат всички основни команди налични на потребителите. С "help <команда>" се извежда информация за конкретна команда. За скролване на конзолата ползвайте Page Up и Page Down.

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
- g++ test.cpp Book.h User.h Library.h -o test -lpdcurses

Compilation(Linux):
- g++ test.cpp Book.h User.h Library.h -o test -lcurses

Note: You can use "help" to get the basic user commands. Typing "help <command>" gives more info on that command's syntax. Use Page Up and Page Down to scroll the console.