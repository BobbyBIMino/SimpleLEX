#pragma once
#include <string>
using namespace std;

class Base
{
public:
	Base();
   bool phrase( string& content);
	bool fout(string content, string type, int num);
protected :
	string  typeName;	
};