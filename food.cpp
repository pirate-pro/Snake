#include "food.h"
food::food()
{

}
food::~food()
{

}
void food::createPos()
{
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;          //控制台结构体类型
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);
	coor.X = scr.srWindow.Right + 1;
	coor.Y = scr.srWindow.Bottom + 1;
	//(rand() % (b-a+1))+ a;
	srand((int)time(0));//产生随机数种子
	x = (rand() % ((coor.X - 6) - (left + 1) + 1)) + (left + 1); //X坐标限制
	y = (rand() % ((coor.Y - 2) - (up + 3) + 1)) + (up + 3); //Y坐标限制
	gotoxy(x, y);
	//SetColor(6);
	cout << "*";
}