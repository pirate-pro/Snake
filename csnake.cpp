#include "csnake.h"
#include<conio.h>
csnake::csnake(int x, int y , int len, dir dir , int m_speed , char m_c )
{
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coord.X = scr.srWindow.Right + 1;
	m_coord.Y = scr.srWindow.Bottom + 1;
	length=len;
	headX=x;
	headY=y;
	speed=m_speed;
	c=m_c;
	m_dir = dir;
	for (int i = 0; i < length; i++)
	{
		unit u1;
		body.push_back(u1);
		switch (dir)
		{
		case UP:
			body[i].x = headX;
			body[i].y = headY - i;
			break;
		case DOWN:
			body[i].x = headX;
			body[i].y = headY + i;
			break;
		case LEFT:
			body[i].x = headX + i;
			body[i].y = headY;
			break;
		case RIGHT:
			body[i].x = headX - i;
			body[i].y = headY;
			break;
		default:
			break;
		}
	}

}
csnake::~csnake()
{
}
void csnake::showSnake()
{
	body[0].c = '@';
	for (int i = 0; i < length; i++)
	{
		body[i].show();
	}
}
void csnake::eraseSnake()
{
	for (int i = 0; i < length; i++)
	{
		body[i].erase();
	}
}
void csnake::move()
{
	//body move
	for (int i = length - 1; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	//head move
	switch (m_dir)
	{
	case UP:
		body[0].y--;
		break;
	case DOWN:
		body[0].y++;
		break;
	case LEFT:
		body[0].x--;
		break;
	case RIGHT:
		body[0].x++;
		break;
	default:
		break;
	}
	showSnake();
	Sleep(speed);
	eraseSnake();
}
void csnake::changeDirection(food &f,int vkValue)
{
	while (true)
	{
		if (_kbhit())
		{                               //如果有按键按下，则_kbhit()函数返回真
			vkValue = _getch();         //使用_getch()函数获取按下的键值
			if (vkValue == 32)
			{
				vkValue = _getch();
			}
			switch (vkValue)
			{
			case 72:									//上下左右72，80，75，77
				if (m_dir == LEFT || m_dir == RIGHT)
				{
					m_dir = UP;
				}
				break;
			case 80:
				if (m_dir == LEFT || m_dir == RIGHT)
				{
					m_dir = DOWN;
				}
				break;
			case 75:
				if (m_dir == UP || m_dir == DOWN)
				{
					m_dir = LEFT;
				}
				break;
			case 77:
				if (m_dir == UP || m_dir == DOWN)
				{
					m_dir = RIGHT;
				}
				break;
			default:
				break;
			}
		}
		if (eatFood(&f))
		{
			score++;
			growup();
			f.erase();
			f.createPos();
		}
		levelup();
		finishgame();
		getGamedata();
		move();
	}
}
bool csnake::eatFood(food *pFood)
{
	if (body[0].x == pFood->x && body[0].y == pFood->y)  //当食物坐标与蛇头坐标相同时，蛇变长，再次产生一个食物
	{

		return true;
	}
	else
		return false;
} 
void csnake::growup()
{
	length++;
	unit unit;
	body.push_back(unit);

}
void csnake::final_interface()
{
	control c;
	int d = 0;
	system("cls");
	c.drawGameArea();
	gotoxy((m_coord.X - left) / 2 - 6, up + 1);
	cout << "Game Over!!!";
	gotoxy(m_coord.X / 2 - 10, m_coord.Y / 2);
	cout << "Your final score:" << score;
	gotoxy(m_coord.X / 2 - 10, m_coord.Y / 2 + 2);
	cout << "Your final level:" << level;
	Sleep(2000);
	system("cls");
	c.drawGameArea();
	gotoxy(m_coord.X / 2 - 10, m_coord.Y / 2 - 2);
	cout << "1.Restart the game";
	gotoxy(m_coord.X / 2 - 10, m_coord.Y / 2);
	cout << "2.Quit the game";
	gotoxy(m_coord.X / 2 - 10, m_coord.Y / 2 + 2);
	cout << "Enter the serial number ";
	gotoxy(m_coord.X / 2 - 10, m_coord.Y / 2 + 3);
	cout << "and press enter to select: ";
	cin >> d;

	switch (d)
	{
	case 1:
		system("cls");
		c.startgame();
		break;
	case 2:
		exit(0);
		break;
	default:
		gotoxy(m_coord.X / 2 - 10, m_coord.Y / 2 - 2); 
		cout << "Input error, please input again!";
		break;
	}
}
void csnake::finishgame()
{
	if (body[0].x >= m_coord.X-6 || body[0].x <= 3 || body[0].y >= m_coord.Y-2 || body[0].y <= 6)	//撞墙情况
	{
		PlaySound(TEXT("dead.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //加入背景音乐
		Sleep(2000);
		final_interface();
	}
	for (int i = 1; i < length; i++)	//撞到自己情况
	{
		if (body[0].x == body[i].x && body[0].y == body[i].y)
		{
			final_interface();
		}
	}
}
void csnake::getGamedata()
{
	gotoxy((m_coord.X - left) / 8 * 5 + 10, up + 1);

	cout << score;

	gotoxy((m_coord.X - left) / 8 * 6.5+10, up + 1);

	cout << level;
}
void csnake::levelup()
{
	if (score <= 3)
	{
		level = 1;
	}
	if (score >= 4 && score < 6)
	{
		speed = 100;
		level = 2;
	}
	if (score >= 6 && score < 8)
	{
		speed = 80;
		level = 3;
	}
	if (score >= 8 && score < 10)
	{
		speed = 30;
		level = 4;
	}
	if (score >= 10)
	{
		speed = 10;
		level = 5;
	}
}