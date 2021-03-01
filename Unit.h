#pragma once
#include<Windows.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")//导入winmm.lib库
using namespace std;
class unit                                //单元类
{
public:
	unit(int x = 10, int y = 5, char pic = '#');
	~unit();
	static void gotoxy(int a,int b);            //光标函数
	void show();								//显示字符函数
	void erase();								//擦除字符函数
	void SetColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0);//设置颜色
public:
	const static int left = 3;                 //左偏移量
	const static int up = 3;                   //上偏移量
	int x;                                     //横坐标
	int y;									   //纵坐标
	char c;                                    //形状
};
