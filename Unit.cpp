#include "Unit.h"
unit::unit(int a, int b, char pic)
{
	x = a;
	y = b;
	c = pic;
}
unit::~unit()
{
}
void unit::gotoxy(int a, int b)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);   //¾ä±ú
	COORD position;          
	position.X = a;
	position.Y = b;
	SetConsoleCursorPosition(screen, position);
}
void unit::show()
{
	gotoxy(x, y);
	//SetColor(4);
	cout << c;
}
void unit::erase()
{
	gotoxy(x, y);
	cout << ' ';
}
void unit::SetColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor | BackGroundColor);
}
