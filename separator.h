#pragma once
#include "base.h"
#define SINGLEQUO 1    // µ¥ÒýºÅ
#define DOUBLEQUO 2  // Ë«ÒýºÅ
#define LLBRACE 3     //×ó´óÀ¨ºÅ
#define LMBRACE 4   //×óÖÐÀ¨ºÅ
#define LSBRACE 5    //×óÐ¡À¨ºÅ
#define RLBRACE 6     //ÓÒ´óÀ¨ºÅ
#define RMBRACE 7   //ÓÒÖÐÀ¨ºÅ
#define RSBRACE 8     //ÓÒÐ¡À¨ºÅ
#define SEMICOLON 9 //·ÖºÅ
#define COMMA  10//¶ººÅ
#define DOT 11//µã
#define LBRACE  12//×ó¼âÀ¨ºÅ
#define RBRACE  13
#define JING 14 //#
#define COLON 15 //:


class Separator :public Base
{
public:
	Separator();
	bool phrase(string& content);
};