#include "control.h"

control::control()
{
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* ��ȡ��׼������ */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right+1;
	m_coor.Y = scr.srWindow.Bottom+1;
}

control::~control()
{
}
void control::HideCursor()			//���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void control::drawGameArea()
{
	unit::gotoxy(unit::left, unit::up);
	for (int j = 0; j < m_coor.X-7; j++)
	{
		cout << "-";
	}

	for (int i = 0; i < m_coor.Y-5; i++)
	{
		unit::gotoxy(unit::left, unit::up + 1 + i);
		cout << "|";
		unit::gotoxy(m_coor.X - 5, unit::up + 1 + i);
		cout << "|";
	}

	unit::gotoxy(unit::left,m_coor.Y - 1);
	for (int k = 0; k < m_coor.X-7; k++)
	{
		cout << "-";
	}

	unit::gotoxy(unit::left + 1, unit::up + 2);
	for (int i = 0; i < m_coor.X-9; i++)
	{
		cout << "-";
	}
}
void control::drawGameInfo()
{
	unit::gotoxy((m_coor.X-unit::left)/8 , unit::up + 1);

	cout << "��Ϸ���ƣ�̰����";

	unit::gotoxy((m_coor.X - unit::left) / 8*3, unit::up + 1);

	cout << "��д�ߣ������";

	unit::gotoxy((m_coor.X - unit::left) / 8*5, unit::up + 1);

	cout << "��ǰ�÷�";

	unit::gotoxy((m_coor.X - unit::left) / 8*6.5, unit::up + 1);

	cout << "��ǰ�ؿ�";


}
void control::startgame()
{
	food m_food ;
	csnake m_csnake ;
	control c;
	c.game_interface();
	c.HideCursor();
	c.drawGameArea();
	c.drawGameInfo();
	m_csnake.getGamedata();
	m_food.createPos();
	int key = 70;
	//s1.startgame();
	PlaySound(TEXT("bgm.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���뱳������
	while (true)
	{
		m_csnake.changeDirection(m_food, key);
		m_csnake.getGamedata();
	}


}
void control::game_interface()	             //��Ϸ��ʼ���棺
{
	system("cls");
	drawGameArea();
	int c = 0;
	unit::gotoxy((m_coor.X - unit::left) / 2-6, unit::up + 1);
	cout << "��ӭ����̰������Ϸ��";
	unit::gotoxy(m_coor.X / 2 - 10,  m_coor.Y / 2 - 2);
	cout << "  1.������ʼ��Ϸ";
	unit::gotoxy(m_coor.X / 2 - 10, m_coor.Y / 2);
	cout << "  2.��Ϸ˵��";
	unit::gotoxy(m_coor.X / 2 - 10, m_coor.Y / 2 + 2);
	cout << "������ź󰴻س�ѡ��";
	cin >> c;

	switch (c)
	{
	case 1:
		system("cls");
		getchar();
		break;
	case 2: system("cls");
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 5); cout << "                          ���ʹ�÷�����ٿ�";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 4); cout << "                          �߿������ɵĳ�ʳ�";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 3); cout << "                   ͬʱ�������ų��µ�ʳ���ų����ٶȱ��";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 2); cout << "   ����ͷײ�������ǽʱ��Ϸ����,��Ϸ�������ѡ��������Ϸ���˳���Ϸ";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 1); cout << "                            ���levelΪ5";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2); cout << "                       ��-��	��-��	��-��	��-��";
		getchar();
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 + 2); cout << "                     ����س����»ص���Ϸ��ʼ����";
		getchar();
		game_interface();
		break;
	default: 
		unit::gotoxy(m_coor.X / 2 - 10, m_coor.Y / 2 - 2); 
		cout << "������������������!";
		game_interface();
		break;
	}
	return;
}
