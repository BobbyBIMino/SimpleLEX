#pragma once
#include "base.h"
#define POSINT 1  //������
#define NEGAINT 2 //������
#define POSDOUBLE 3//��������
#define NEGADOUBLE 4
#define TRUE 5
#define FALSE 6

class Num : public Base
{
public:
	Num();
	bool phrase(string& content);

};