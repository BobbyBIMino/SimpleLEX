#include "stdafx.h"
#include "separator.h"
Separator::Separator()
{
	typeName = "Separator";
}

bool Separator::phrase(string& content)
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
	if (c == "'")
	{
		fout(c, typeName,SINGLEQUO );
	}
	else  if (c == "\"")
	{
		fout(c, typeName, DOUBLEQUO);
	}
	else if (c == "{")
	{
		fout(c, typeName,LLBRACE );
	}
	else if (c == "[")
	{
		fout(c, typeName, LMBRACE);
	}
	else if (c == "(")
	{
		fout(c, typeName,LSBRACE );
	}
	else if (c == "}")
	{
		fout(c, typeName,RLBRACE );
	}
	else if (c == "]")
	{
		fout(c, typeName, RMBRACE);
	}
	else if (c == ")")
	{
		fout(c, typeName, RSBRACE);
	}

	else if (c == ";")
	{
		fout(c, typeName,SEMICOLON );
	}
	else if (c == ",")
	{
		fout(c, typeName, COMMA);
	}
	else if (c == ".")
	{
		fout(c, typeName, DOT);
	}
	else if (c == "<")
	{
		fout(c, typeName, LBRACE);
	}
	else if (c == ">")
	{
		fout(c, typeName,RBRACE );
	}
	else if (c == "#")
	{
		fout(c, typeName, JING);
	}
	else if (c == ":")
	{
		if (content.substr(1, 1) == ":")
		{
			return false;
		}
		fout(c, typeName, COLON);
	}
	else
	{
		return false;
	}
	if (content.length() >=1)
	{
		content.replace(0, 1, "");
	}
	return true;
}
