#pragma once
#include<Windows.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")//����winmm.lib��
using namespace std;
class unit                                //��Ԫ��
{
public:
	unit(int x = 10, int y = 5, char pic = '#');
	~unit();
	static void gotoxy(int a,int b);            //��꺯��
	void show();								//��ʾ�ַ�����
	void erase();								//�����ַ�����
	void SetColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0);//������ɫ
public:
	const static int left = 3;                 //��ƫ����
	const static int up = 3;                   //��ƫ����
	int x;                                     //������
	int y;									   //������
	char c;                                    //��״
};
