#pragma once
#include "base.h"
#define POSINT 1  //正整数
#define NEGAINT 2 //负整数
#define POSDOUBLE 3//正浮点数
#define NEGADOUBLE 4
#define TRUE 5
#define FALSE 6

class Num : public Base
{
public:
	Num();
	bool phrase(string& content);

};