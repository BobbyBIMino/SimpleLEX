#pragma once
#include "base.h"
#define EQU 1
#define ADDEQU 2
#define SUBEQU 3
#define DIVEQU 4
#define MULEQU 5
#define MODEQU 6

class Assignment : public Base
{
public :
	Assignment();
	bool phrase(string& content);

};