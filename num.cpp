#include "stdafx.h"
#include "num.h"
/*
在写num时先声明
*/
Num::Num()
{
	typeName = "Num";
}
bool Num::phrase(string& content)
{/*
	string c = "";
	//判断是否为空，如果是空就可以直接返回
	if (!content.empty())
	{
		c = content.substr(0, 4);
	}
	else
	{
		return false;
	}
	//识别true和false，考虑到true和false后面只能跟";"
	if (c == "true")
	{
		if (content.size() > 4)
		{
			if (content[4] != ';')
			{
				return false;
			}
		}
		//content.size==4或true后面是分号
		fout(c, typeName, TRUE);
		content.replace(0, 4, "");
		return true;
	}
	c = content.substr(0, 5);
	if (c == "false")
	{
		if (content.size() > 5)
		{
			if (content[5] != ';')
			{
				return false;
			}
		}
		//content.size==5或true后面是分号
		fout(c, typeName, FALSE);
		content.replace(0, 5, "");
		return true;
	}
	c = "";
	//识别负数
	bool fdot = false;
	bool fng = false;

	if (content[0] == '-')
	{

		c = c + "-";
		fng = true;
	}
	for (int i = fng;i < content.size();i++)
	{
		if ((content[i] >= '0') && (content[i] <= '9'))
		{
			c = c + content[i];
		}
		else if ((content[i] == '.') && !fdot)
		{
			c = c + content[i];
			fdot = true;
		}
		//字符串未结束但出现了除数字之外的字符，但字符本来就允许出现在num后面
		else if ((content[i] == '+') || (content[i] == '-') || (content[i] == '*') || (content[i] == '/') || (content[i] == '%') || (content[i] == ',') || (content[i] == ';'))
		{
			break;
		}
		//表示出现错误，注意如果出现多个点也表示出现错误
		else
		{
			return false;
		}

		if (fng)
		{
			if (fdot)
			{
				fout(c, typeName, NEGADOUBLE);
			}
			else
			{
				fout(c, typeName, NEGAINT);

			}
		}
		else
		{
			if (fdot)
			{
				fout(c, typeName, POSDOUBLE);

			}
			else
			{
				fout(c, typeName, POSINT);

			}

		}
		content.replace(0, c.size(), "");
		return true;

	}
	return false;
}
*/

//初始状态
//如果fng等于1表示出现了负号。
bool fng = false;
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
				state = 6;
			}
			else if (content[i] == '-')
			{
				c = c + content[i];
				fng = 1;
				state = 1;
			}
			else if (content[i] == 't')
			{
				c = c + content[i];

				state = 7;
			}
			else if (content[i] == 'f')
			{
				c = c + content[i];
				state = 8;
			}
			else if ((content[i] >= '0') && (content[i] <= '9'))
			{
				i--;
				state = 1;
			}
			else {
				state = 6;
			}
			break;
		case 1:
			i++;
			if (content.size() <= i)
			{
				state = 6;
			}
			else if ((content[i] >= '0') && (content[i] <= '9'))
			{
				c = c + content[i];
				state = 2;
			}
			else
			{
				state = 6;
			}
			break;
		case 2:
			i++;
			if (content.size() <= i)
			{
				state = 5;
			}
			else if ((content[i] >= '0') && (content[i] <= '9'))
			{
				c = c + content[i];
				state = 2;
			}
			//不是数字，但可以是一些分隔符
			else if ((content[i] == '+') || (content[i] == '-') || (content[i] == '*') || (content[i] == '/') || (content[i] == '%') || (content[i] == ',') || (content[i] == ';')|| (content[i] == ')'))
			{
				state = 5;
			}
			//是点，标记为浮点数
			else if ((content[i] == '.'))
			{
				c = c + content[i];
				state = 3;
			}
			else
			{
				state = 6;
			}
			break;
		case 3:
			i++;
			//字符串尾
			if (content.size() <= i)
			{
				state = 6;
			}
			else if ((content[i]  >=  '0') && (content[i] <= '9'))
			{
				c = c + content[i];
				state = 4;
			}
			else
			{
				state = 6;
			}
			break;
		case 4:
			//字符串尾
			i++;
			if (content.size() <= i)
			{
				state = 11;
			}
			else if ((content[i] >= '0') && (content[i] <= '9'))
			{
				c = c + content[i];
				state = 4;
			}
			else if ((content[i] == '+') || (content[i] == '-') || (content[i] == '*') || (content[i] == '/') || (content[i] == '%') || (content[i] == ',') || (content[i] == ';') || (content[i] == ')'))
			{
				state = 11;
			}
			else {
				state = 6;
			}
			break;
		case 5:
			if (fng == 1)
			{
				fout(c, typeName, NEGAINT);

			}
			else {
				fout(c, typeName, POSINT);
			}
			content.replace(0, c.size(), "");
			return true;
			break;
		case 6:
			return false;
			break;
		case 7:
			if (content.size() < 4)
			{
				state = 6;
			}else if  (content.substr(0, 4) == "true")
			{
				
				c = "true";
				state = 9;
			}
			else {
				state = 6;
			}
			break;
		case 8:
			if (content.size() < 5)
			{
				state = 6;
			}else if (content.substr(0, 5) == "false")
			{
				
				c = "false";
				state = 10;
			}
			else {
				state = 6;
			}

			break;
		case 9:
		
			if ((content.size() == 4)||(content[4] == ';'))
			{
				fout(c, typeName,TRUE);
				content.replace(0, c.size(), "");
				return true;
			}
			else {
				state = 6;
			}
			break;
		case 10:

			if ((content.size() == 5) || (content[5] == ';'))
			{
				fout(c, typeName, FALSE);
				content.replace(0, c.size(), "");
				return true;
			}
			else {
				state = 6;
			}
			break;
		case 11:
			if (fng == 1)
			{
				fout(c, typeName, NEGADOUBLE);

			}
			else {
				fout(c, typeName, POSDOUBLE);
			}
			content.replace(0, c.size(), "");
			return true;
			break;
			
		}
	}
}