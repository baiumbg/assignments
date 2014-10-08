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
- g++ driver.cpp Minesweeper.h -o minesweeper -lpdcurses

�����������(Ubuntu):
- g++ driver.cpp Minesweeper.h -o minesweeper -lcurses

���������: ��� ������� �� ������ ����������� � ������� �� ������ �� ������ � �������� �� ������. ������ �� ���� �� ���� ��-������ �� 30�20 (������ � �������) � �� ���� �� � ��-����� �� 4�4. ��������� ������ �� ����� �������� � �������� ����� ��� (����� �� ������� ������, ���� ���� �������). ���������� �� ������ �������� ����� ���� �� ����� ������������ � ������ (������� �� ���� ���� - ��������*(��������������/12)). �� ����� ������� ���������� �� ������ ��������� � ��� ��������.

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