#pragma once
#include "base.h"
#include <vector>
class Id : public Base
{
public:
	Id();
	bool phrase(string& content);
private :
	vector<string>  cont;

};