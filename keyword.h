#pragma once
#include "base.h"
#define IF  1
#define FOR 2

#define MAIN 7
#define CASE 8
#define EXIT 10
#define ELSE 3

#define WHILE 4
#define USING 13
#define BREAK 11

#define PUBLIC 15
#define RETURN 9
#define SWITCH 12

#define CONTINUE  5
#define INCLUDE 6

#define NAMESPACE 14
#define PRIVATE 16
#define PROTECTED 17

class Keyword : public Base
{
public:
	Keyword();
	bool phrase(string& content);

};
 
