#pragma once
#include "base.h"
#define ADD 1  // +
#define SUB 2   // -
#define MUL 3  // *
#define DIV 4 // /
#define INC 5  //++
#define DEC 6  //--
#define MOD 7  //%
#define NOT 8  //!
#define NEUQAL 9 //!=
#define EQUAL 10 //==
#define LARGER 11 //>
#define SMALLER 12 //<
#define NLARGER 13  //<=
#define NSMALLER 14 //>=
#define DOMAIN 15  //::
#define INSTREAM 16 //<<
#define OUTSTREAM 17 //>>
#define AND 18// &&
#define OR 19 //||

class Operation : public Base
{
public:
	Operation();
	bool phrase(string& content);

};

