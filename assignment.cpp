#include "stdafx.h"
#include "assignment.h"

Assignment::Assignment()
{
	typeName = "Assignment";
}

bool Assignment::phrase(string& content)
{
	string c = "";
	if (!content.empty())
	{
		c = content.substr(0, 1);
	}
	else
	{
		return false;
	}
	
	if (c == "=")
	{
		fout(c, typeName, EQU);
		content.replace(0, 1, "");
	}
	else
	{
		c = content.substr(0, 2);
		if (c == "+=")
		{
			fout(c, typeName, ADDEQU);
		}
		else if (c == "-=")
		{
			fout(c, typeName, SUBEQU);
		}
		else if (c == "*=")
		{
			fout(c, typeName, MULEQU);
		}
		else if (c == "/=")
		{
			fout(c, typeName, DIVEQU);
		}
		else if (c == "%=")
		{
			fout(c, typeName, MODEQU);
		}
		else
			//∆•≈‰ ß∞‹£¨∑µªÿ
		{
			return false;
		}
		content.replace(0, 2, "");
		return true;
		}

	return false;
}
