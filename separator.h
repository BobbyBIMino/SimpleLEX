#pragma once
#include "base.h"
#define SINGLEQUO 1    // ������
#define DOUBLEQUO 2  // ˫����
#define LLBRACE 3     //�������
#define LMBRACE 4   //��������
#define LSBRACE 5    //��С����
#define RLBRACE 6     //�Ҵ�����
#define RMBRACE 7   //��������
#define RSBRACE 8     //��С����
#define SEMICOLON 9 //�ֺ�
#define COMMA  10//����
#define DOT 11//��
#define LBRACE  12//�������
#define RBRACE  13
#define JING 14 //#
#define COLON 15 //:


class Separator :public Base
{
public:
	Separator();
	bool phrase(string& content);
};