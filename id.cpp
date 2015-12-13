#include "stdafx.h"
#include "id.h"

Id::Id()
{
	typeName = "ID";
}

bool Id::phrase(string & content)

/*	string c = "";
	if (((content[0] >= 'A') && (content[0] <= 'Z')) || ((content[0] >= 'a') && (content[0] <= 'z') )| (content[0] == '_'))
	{
		//加上第一个字符
		c = c + content[0];
		if (content.size() > 1)
		{
			for (int i = 1;i < content.size(); i++)
			{
				if (((content[i] >= 'A') && (content[i] <= 'Z')) || ((content[i] >= 'a') && (content[i] <= 'z')) | ((content[i] >= '0') && (content[i] <= '9')) || (content[i] == '_'))
					//第i个字符仍然是标识符中可以出现的字符
				{
					c = c + content[i];
				}
				//出现意料之外的字符，判断是不是分隔符，op，等符号
				else if ((content[i] == '<') || (content[i] == '#') || (content[i] == '%') | (content[i] == '*') | (content[i] == '(') || (content[i] == '{') || (content[i] == '=') || (content[i] == '+') | (content[i] == '-') | (content[i] == '/') || (content[i] == '[') || (content[i] == '>') || (content[i] == '>') || (content[i] == '.') || (content[i] == '\"') || (content[i] == ';')|| (content[i] == ':')|| (content[i] == ')')|| (content[i] == ']')|| (content[i] == ','))
					//退出循环
				{
					break;
				}
				else
					//出现意料之外的字，不是有用的符号,直接返回
				{
					return false;
				}
			}
		}
		//c所有的字母都是标识符中可以出现的字符，要将c写入文件，关键是如何确定c的编号，在同一个文件中，同一个标识符应该被识别为同一个。
		if (cont.empty())
		{
			cont.push_back(c);
			fout(c, typeName, 0);
			content.replace(0, c.size(), "");
			return true;
		}
		else
		{

				for (int i = 0;i < cont.size();i++)
				{
					//c已出现过，标记位置并输出返回。
					if (c == cont.at(i))
					{
						fout(c, typeName, i);
						content.replace(0, c.size(), "");
						return true;

					}
				}
			//c未出现，c压入向量并输出。
			cont.push_back(c);
			fout(c, typeName,cont.size()-1);
			content.replace(0, c.size(), "");
			return true;
		}

	}
	else
		//第一个字符不符合要求，返回
	{
		return false;



	}
}
*/
{	//初始状态
	int state = 0;

	string c = "";
	//记录当前
	int i = 0;
	while (1)
	{
		switch (state)
		{
		case 0:
			if (content.size() <= i)
			{
				state = 3;
			}
			else if (((content[i] >= 'A') && (content[i] < 'Z')) || ((content[i] >= 'a') && (content[i] <= 'z')) | (content[i] == '_'))
			{
				c = c + content[i];
				state = 1;
			}
			else
				//第一个字符不合法，退出。
			{
				state = 3;
			}
			break;
		case 1:
			i++;
			if (content.size() == i)
			{
				state = 2;
			}
			else if (((content[i] >= 'A') && (content[i] <= 'Z')) || ((content[i] >= 'a') && (content[i] <= 'z')) | ((content[i] >= '0') && (content[i] <= '9')) || (content[i] == '_'))
			{
				c = c + content[i];
				state = 1;
			}
			//后面不是标识符中可出现的字符但是是标识符中允许出现的字符，输出可输出该标识符	
			else 	if ((content[i] == '<') || (content[i] == '#') || (content[i] == '%') | (content[i] == '*') | (content[i] == '(') || (content[i] == '{') || (content[i] == '=') || (content[i] == '+') | (content[i] == '-') | (content[i] == '/') || (content[i] == '[') || (content[i] == '>') || (content[i] == '>') || (content[i] == '.') || (content[i] == '\"') || (content[i] == ';') || (content[i] == ':') || (content[i] == ')') || (content[i] == ']') || (content[i] == ','))
			{
				state = 2;
			}
			else {
				state = 3;
			}
			break;
		case 2:
			//输出字符串，结束状态。
			//c所有的字母都是标识符中可以出现的字符，要将c写入文件，关键是如何确定c的编号，在同一个文件中，同一个标识符应该被识别为同一个。
			if (cont.empty())
			{
				cont.push_back(c);
				fout(c, typeName, 0);
				content.replace(0, c.size(), "");
				return true;
			}
			else
			{
				for (int i = 0;i < cont.size();i++)
				{
					//c已出现过，标记位置并输出返回。
					if (c == cont.at(i))
					{
						fout(c, typeName, i);
						content.replace(0, c.size(), "");
						return true;
					}
				}
				//c未出现，c压入向量并输出。
				cont.push_back(c);
				fout(c, typeName, cont.size() - 1);
				content.replace(0, c.size(), "");
				return true;
			}
				break;
		case 3:
			//标识符不合法
			return false;
			break;

		}

	}
}