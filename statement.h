#pragma once
#include "base.h"
#define STATIC 1
#define CONST 2
#define UNSIGNED 3
#define INT 4
#define DOUBLE 5
#define FLOAT 6
#define BOOL 7
#define VOID 8
#define INLINE 9
#define FRIEND 10
#define NEW 11
#define VIRTUAL 12

class Statement : public Base
{
public:
	Statement();
	bool phrase(string& content);

};