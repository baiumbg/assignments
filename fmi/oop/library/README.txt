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
- g++ test.cpp Book.h User.h Library.h -o test -lpdcurses

Компилация(Ubuntu):
- g++ test.cpp Book.h User.h Library.h -o test -lcurses

Забележка: Напишете "help" за основните команди. Чрез "help <команда>" можете да научите повече за синтаксиса на дадена команда. За скролване на конзолата използвайте Page Up и Page Down.

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
