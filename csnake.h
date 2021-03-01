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
		void changeDirection(food &f,int vkValue);   //上下左右
		void move();                    //移动函数
		bool eatFood(food *pFood);		//判断是否吃到食物
		void showSnake();				//显示蛇
		void eraseSnake();				//擦除蛇
		void growup();					//蛇张长
		void final_interface();			//游戏结束界面
		void finishgame();				//判断游戏是否结束
		void getGamedata();				//获取游戏数据
		void levelup();                 //难度提升
		COORD m_coord;
public:
		int length;
		int headX;
		int headY;
		int speed;
		int c;
		dir m_dir;
		vector<unit>body;             
		int score;                 //记录分数
		int level;                 //记录难度
};
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 