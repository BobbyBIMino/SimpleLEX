#include "stdafx.h"
#include "operation.h"
/*
若‘-’直接跟数字将会被识别为负数，‘-’号后跟字符或者空格后跟数字，将会被识别成负号
*/
Operation::Operation()
{
	typeName = "Operation";
}
bool Operation::phrase(string& content)
/*{
	string c = "";
	if (!content.empty())
	{
		c = content.substr(0, 1);
	}
	else
	{
		return false;
	}

	if (c == "+")
	{
		if (content.size() == 1)
		{
			fout(c, typeName, ADD);
			content.replace(0, 1, "");
		}
		else
		{
			if (content.substr(1, 1) == "+")
			{
				c = c + "+";
				fout(c, typeName, INC);
				content.replace(0, 2, "");
				return true;
			}
			else
				if (content.substr(1, 1) == "=")
				{
					return false;
				}
				else
				{
					fout(c, typeName, ADD);
					content.replace(0, 1, "");
					return true;
				}
		}
	}
	else if (c == "-")
	{
		if (content.size() == 1)
		{
			fout(c, typeName, SUB);
			content.replace(0, 1, "");
		}
		else
		{
			if (content.substr(1, 1) == "-")
			{
				c = c + "-";
				fout(c, typeName, DEC);
				content.replace(0, 2, "");
			}
			else if (content.substr(1, 1) == "=")
			{
				return false;
			}
			else
			{
				fout(c, typeName, SUB);
				content.replace(0, 1, "");
			}
		}

	}
	else if (c == "*")
	{

		if (content.size() == 1)
		{
			fout(c, typeName, MUL);
			content.replace(0, 1, "");
		}
		else
		{
			if (content.substr(1, 1) == "=")
			{
				return false;
			}
			else
			{
				fout(c, typeName, MUL);
				content.replace(0, 1, "");
			}
		}

	}
	else if (c == "/")
	{
		if (content.size() == 1)
		{
			fout(c, typeName, DIV);
			content.replace(0, 1, "");
		}
		else
		{
			if (content.substr(1, 1) == "=")
			{
				return false;
			}
			else
			{
				fout(c, typeName, DIV);
				content.replace(0, 1, "");
			}
		}
	}
	else if (c == "%")
	{
		if (content.size() == 1)
		{
			fout(c, typeName, MOD);
			content.replace(0, 1, "");
		}
		else
		{
			if (content.substr(1, 1) == "=")
			{
				return false;
			}
			else
			{
				fout(c, typeName, MOD);
				content.replace(0, 1, "");
			}
		}

	}
	else if (c == "!")
	{
		if (content.substr(1, 1) == "=")
		{
			c = c + "=";
			fout(c, typeName, NEUQAL);
			content.replace(0, 2, "");
			return false;
		}
		else
		{
			fout(c, typeName, NOT);
			content.replace(0, 1, "");
		}
	}
	else if (c == "=")
	{
		if (content.substr(1, 1) == "=")
		{
			c = c + "=";
			fout(c, typeName, EQUAL);
			content.replace(0, 2, "");
		}
		else
		{
			return false;
		}
	}
	else if (c == ">")
	{
		if (content.substr(1, 1) == "=")
		{
			c = c + "=";
			fout(c, typeName, NSMALLER);
			content.replace(0, 2, "");
		}
		else if (content.substr(1, 1) == ">")
		{
			c = c + ">";
			fout(c, typeName, OUTSTREAM);
			content.replace(0, 2, "");
		}
		else {
			fout(c, typeName, SMALLER);
			content.replace(0, 1, "");
		}
	}
	else if (c == "<")
	{
		if (content.substr(1, 1) == "=")
		{
			c = c + "=";
			fout(c, typeName, NLARGER);
			content.replace(0, 2, "");
		}
		else if (content.substr(1, 1) == "<")
		{
			c = c + "<";
			fout(c, typeName, INSTREAM);
			content.replace(0, 2, "");
		}
		else {
			fout(c, typeName, LARGER);
			content.replace(0, 1, "");
		}
	}
	else if (c == ":")
	{
		if (content.substr(1, 1) == ":")
		{
			c = c + ":";
			fout(c, typeName, DOMAIN);
			content.replace(0, 2, "");
		}
		else
		{
			return false;
		}
	}
	else if (c == "&")
	{
		if (content.substr(1, 1) == "&")
		{
			c = c + "&";
			fout(c, typeName, AND);
			content.replace(0, 2, "");
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (c == "|")
	{
		if (content.substr(1, 1) == "|")
		{
			c = c + "|";
			fout(c, typeName, OR);
			content.replace(0, 2, "");
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	return false;
}*/

{
	string c = "";
	int state = 0;
	int i = 0;
	while (1)
	{
		switch (state)
		{
		case 0:
			if (content.size() <= i)
			{
				state = 22;
			}
			else if (content[i] == '+')
			{
				c = c + content[i];
				state = 1;
			}
			else if (content[i] == '*')
			{
				c = c + content[i];
				state = 4;
			}
			else if (content[i] == '-')
			{
				c = c + content[i];
				state = 5;
			}
			else if (content[i] == '/')
			{
				c = c + content[i];
				state = 8;
			}
			else if (content[i] == '%')
			{
				c = c + content[i];
				state = 9;
			}
			else if (content[i] == '>')
			{
				c = c + content[i];

				state = 10;
			}
			else if (content[i] == '<')
			{
				c = c + content[i];
				state = 13;
			}
			else if (content[i] == '!')
			{
				c = c + content[i];
				state = 16;
			}
			else if (content[i] == '=')
			{
				c = c + content[i];
				state = 18;
			}
			else if (content[i] == ':')
			{
				c = c + content[i];
				state = 20;
			}
			else if (content[i] == '&')
			{
				c = c + content[i];
				state = 23;
			}
			else if (content[i] == '|')
			{
				c = c + content[i];
				state = 25;
			}
			else
			{
				state = 22;
			}

			break;
		case 1:
			i++;
			if (content.size() <= i)
			{
				state = 2;
			}
			else if (content[i] == '=')
			{
				state = 22;
			}
			else if (content[i] == '+')
			{
				c = c + content[i];
				state = 3;
			}
			else {
				state = 2;
			}
			break;
		case 2:
			fout(c, typeName, ADD);
			content.replace(0, 1, "");
			return true;
			break;
		case 3:
			fout(c, typeName, INC);
			content.replace(0, 2, "");
			return true;
			break;
		case 4:
			i++;
			if (content.size() <= i)
			{
				fout(c, typeName, MUL);
				content.replace(0, 1, "");
				return  true;

			}
			else if (content[i] == '=')
			{
				state = 22;
			}
			else {
				fout(c, typeName, MUL);
				content.replace(0, 1, "");
				return  true;

			}

			break;
		case 5:
			i++;
			if (content.size() <= i)
			{
				state = 7;
			}
			else if ((content[i] == '=')||(content[i] >= '0'&&content[i] <= '9'))
			{
				state = 22;
			}
			else if (content[i] == '-')
			{
				c = c + content[i];
				state = 6;
			}
			else {
				state = 7;
			}
			break;
		case 6:
			fout(c, typeName, INC);
			content.replace(0, 2, "");
			return true;
			break;
		case 7:
			fout(c, typeName, SUB);
			content.replace(0, 1, "");
			return true;
			break;
		case 8:
			i++;
			if (content.size() <= i)
			{
				fout(c, typeName, DIV);
				content.replace(0, 1, "");
				return  true;

			}
			else if (content[i] == '=')
			{
				state = 22;
			}
			else {
				fout(c, typeName, DIV);
				content.replace(0, 1, "");
				return  true;
			}
			break;
		case 9:
			i++;
			if (content.size() <= i)
			{
				fout(c, typeName, MOD);
				content.replace(0, 1, "");
				return  true;

			}
			else if (content[i] == '=')
			{
				state = 22;
			}
			else {
				fout(c, typeName, MOD);
				content.replace(0, 1, "");
				return  true;

			}
			break;
		case 10:
			i++;
			if (content.size() <= i)
			{
				fout(c, typeName, LARGER);
				content.replace(0, 1, "");
				return true;
			}
			else if (content[i] == '=')
			{
				c = c + content[i];
				state = 12;
			}
			else if (content[i] == '>')
			{
				c = c + content[i];
				state = 11;
			}
			else
			{
				fout(c, typeName, LARGER);
				content.replace(0, 1, "");
				return true;
			}
			break;
		case 11:
			fout(c, typeName, OUTSTREAM);
			content.replace(0, 2, "");
			return true;
			break;
		case 12:
			fout(c, typeName, NSMALLER);
			content.replace(0, 2, "");
			return true;
			break;
		case 13:
			i++;
			if (content.size() <= i)
			{
				fout(c, typeName, SMALLER);
				content.replace(0, 1, "");
				return true;
			}
			else if (content[i] == '=')
			{
				state = 15;
				c = c + content[i];
			}
			else if (content[i] == '>')
			{
				state = 14;
				c = c + content[i];
			}
			else
			{
				fout(c, typeName, SMALLER);
				content.replace(0, 1, "");
				return true;
			}
			break;
		case 14:
			fout(c, typeName, INSTREAM);
			content.replace(0, 2, "");
			return true;
			break;
		case 15:
			fout(c, typeName, NLARGER);
			content.replace(0, 2, "");
			return true;
			break;
		case 16:
			i++;
			if (content.size() <= i)
			{
				fout(c, typeName, NOT);
				content.replace(0, 1, "");
				return true;
			}
			else if (content[i] == '=')
			{
				state = 17;
				c = c + content[i];
			}
			else
			{
				fout(c, typeName, NOT);
				content.replace(0, 1, "");
				return true;
			}
			break;
		case 17:
			fout(c, typeName, NEUQAL);
			content.replace(0, 2, "");
			return true;
			break;
		case 18:
			i++;
			if (content.size() <= i)
			{
				state = 22;
			}
			else if (content[i] == '=')
			{
				state = 19;
				c = c + content[i];
			}
			else
			{
				state == 22;
			}
			break;
		case 19:
			fout(c, typeName, EQUAL);
			content.replace(0, 2, "");
			return true;
			break;
		case 20:
			i++;
			if (content.size() <= i)
			{
				state = 22;
			}
			else if (content[i] == ':')
			{
				state = 21;
				c = c + content[i];
			}
			else
			{
				state == 22;
			}
			break;
		case 21:
			fout(c, typeName, DOMAIN);
			content.replace(0, 2, "");
			return true;
			break;
		case 22:
			return false;
			break;
		case 23:
			i++;
			if (content.size() <= i)
			{
				state = 22;
			}
			else if (content[i] == '&')
			{
				state = 24;
				c = c + content[i];
			}
			else
			{
				state == 22;
			}
			break;
		case 24:
			fout(c, typeName, AND);
			content.replace(0, 2, "");
			return true;
			break;
		case 25:
			i++;
			if (content.size() <= i)
			{
				state = 22;
			}
			else if (content[i] == '|')
			{
				state = 26;
				c = c + content[i];
			}
			else
			{
				state == 22;
			}
			break;
		case 26:
			fout(c, typeName, AND);
			content.replace(0, 2, "");
			return true;
			break;


		}
	}
}