#pragma once
#include "base.h"
#define HANG 1
#define DUAN 2
class Note : public Base
{
public:
	Note();
	bool phrase(string& content);

};