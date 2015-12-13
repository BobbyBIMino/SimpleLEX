#include "stdafx.h"
#include "base.h"
#include <fstream>
using namespace std;

Base::Base()
{
}

bool Base::phrase(string& content)
{
	return false;
}


bool Base::fout(string content, string type, int num)
{
	ofstream out("output1.txt", ios::app);
	out << "<" << content << "," << type << "," << num << ">\n";
	out.close();
	return false;
}
