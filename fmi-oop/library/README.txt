���������:

����������� �� ������������(Windows):
�������������� ������ � ����������:
- pdcurses.dll � MinGW/bin
- pdcurses.lib � MinGW/lib
- curses.h, panel.h � MinGW/include

����������� �� ������������(Ubuntu):
- �������� ���������
- �������� "sudo apt-get install libncurses5-dev"

�����������(Windows):
- g++ test.cpp Book.h User.h Library.h -o test -lpdcurses

�����������(Ubuntu):
- g++ test.cpp Book.h User.h Library.h -o test -lcurses

���������: � ��������� "help" �� �������� ������ ������� ������� ������� �� �������������. � "help <�������>" �� ������� ���������� �� ��������� �������. �� ��������� �� ��������� ��������� Page Up � Page Down.

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