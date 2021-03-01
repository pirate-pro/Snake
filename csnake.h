#pragma once
#include "Unit.h"
#include "food.h"
#include<vector>
typedef enum dir{
	UP, DOWN, LEFT, RIGHT
};
class food;
class csnake :
	public unit
{
public:

		csnake(int x = 40, int y = 10, int length = 4, dir dir = RIGHT, int speed = 200, char c = '#');
		virtual ~csnake();
		void changeDirection(food &f,int vkValue);   //��������
		void move();                    //�ƶ�����
		bool eatFood(food *pFood);		//�ж��Ƿ�Ե�ʳ��
		void showSnake();				//��ʾ��
		void eraseSnake();				//������
		void growup();					//���ų�
		void final_interface();			//��Ϸ��������
		void finishgame();				//�ж���Ϸ�Ƿ����
		void getGamedata();				//��ȡ��Ϸ����
		void levelup();                 //�Ѷ�����
		COORD m_coord;
public:
		int length;
		int headX;
		int headY;
		int speed;
		int c;
		dir m_dir;
		vector<unit>body;             
		int score;                 //��¼����
		int level;                 //��¼�Ѷ�
};
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 