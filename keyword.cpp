#include "stdafx.h"
#include "keyword.h"
/*

afkjdlbnakjdbnak
akjbklblkajbnka.d
asdvskldnblajbnaekrjngo;qenbk.afd
*/
Keyword::Keyword()
{
	typeName = "Keyword";
}
bool Keyword::phrase(string& content)
{
	string c = "";
	if (content.size() >= 2)
	{
		c = content.substr(0, 2);
	}
	else
	{
		return false;
	}
	// 两个字母
	if (c == "if")
	{
		if (content.size() >= 3)
		{
			if (((content[2] >= 'A') && (content[2] <= 'Z')) || ((content[2] >= 'a') && (content[2] <= 'z')) || ((content[2] >= '0') && (content[2] <= '9')) || (content[2] == '_'))
			{
				return false;
			}
			else
			{
				fout(c, typeName, IF);
				content.replace(0, 2, "");
				return true;
			}
		}
		else
		{
			fout(c, typeName, IF);
			content = "";
			return true;
		}
	}
	//三个字母
	if (content.size() >= 3)
	{
		c = content.substr(0, 3);
	}
	//单词只有两个字母但不是if时的情况
	else
	{
		return false;
	}

	if (c == "for")
	{
		if (content.size() >= 4)
		{
			if (((content[3] >= 'A') && (content[3] <= 'Z')) || ((content[3] >= 'a') && (content[3] <= 'z')) || ((content[3] >= '0') && (content[3] <= '9')) || (content[3] == '_'))
			{
				return false;
			}
			//for之后有符号，但不是标识符
			else
			{
				fout(c, typeName, FOR);
				content.replace(0, 3, "");
				return true;
			}
		}
		else
			//for之后无符号
		{
			fout(c, typeName, FOR);
			content = "";
			return true;
		}
	}
		if (content.size() >= 4)
		{
			c = content.substr(0, 4);
		}
		//单词只有三个字符但不是for时的情况
		else
		{
			return false;
		}
		if ((c == "else") | (c == "exit") | (c == "case") | (c == "main"))
		{
			if (content.size() >= 5)
			{
				if (((content[4] >= 'A') && (content[4] <= 'Z')) || ((content[4] >= 'a') && (content[4] <= 'z')) || ((content[4] >= '0') && (content[4] <= '9')) || (content[4] == '_'))
				{
					return false;
				}
				//四个字符之后有符号，但不是标识符
				else
				{
					if (c == "else")
					{
						fout(c, typeName, ELSE);
					}
					else if (c == "exit")
					{
						fout(c, typeName, EXIT);
					}
					else if (c == "case")
					{
						fout(c, typeName, CASE);
					}
					else if (c == "main")
					{
						fout(c, typeName, MAIN);
					}
					content.replace(0, 4, "");
					return true;
				}
			}
			else
				//四个字符之后无符号
			{
				if (c == "else")
				{
					fout(c, typeName, ELSE);
				}
				else if (c == "exit")
				{
					fout(c, typeName, EXIT);
				}
				else if (c == "case")
				{
					fout(c, typeName, CASE);
				}
				else if (c == "main")
				{
					fout(c, typeName, MAIN);
				}
				content = "";
				return true;
			}
		}
		if (content.size() >= 5)
		{
			c = content.substr(0, 5);
		}
		//单词只有四个字符，但不是关键字
		else
		{
			return false;
		}
		if ((c == "while") | (c == "break") | (c == "using"))
		{
			if (content.size() >= 6)
			{
				if (((content[5] >= 'A') && (content[5] <= 'Z')) || ((content[5] >= 'a') && (content[5] <= 'z')) || ((content[5] >= '0') && (content[5] <= '9')) || (content[5] == '_'))
				{
					return false;
				}
				//五个字符之后有符号，但不是标识符
				else
				{
					if (c == "while")
					{
						fout(c, typeName, WHILE);
					}
					else if (c == "break")
					{
						fout(c, typeName, BREAK);
					}
					else if (c == "using")
					{
						fout(c, typeName, USING);
					}

					content.replace(0, 5, "");
					return true;
				}
			}
			else
				//五个字符之后无符号
			{
				if (c == "while")
				{
					fout(c, typeName, WHILE);
				}
				else if (c == "break")
				{
					fout(c, typeName, BREAK);
				}
				else if (c == "using")
				{
					fout(c, typeName, USING);
				}

				content = "";
				return true;
			}
		}
		if (content.size() >= 6)
		{
			c = content.substr(0, 6);
		}
		//单词只有五个字符，但不是关键字
		else
		{
			return false;
		}
		if ((c == "switch") | (c == "return") | (c == "public"))
		{
			if (content.size() >= 7)
			{
				if (((content[6] >= 'A') && (content[6] <= 'Z')) || ((content[6] >= 'a') && (content[6] <= 'z')) || ((content[6] >= '0') && (content[6] <= '9')) || (content[6] == '_'))
				{
					return false;
				}
				//六个字符之后有符号，但不是标识符
				else
				{
					if (c == "switch")
					{
						fout(c, typeName, SWITCH);
					}
					else if (c == "return")
					{
						fout(c, typeName, RETURN);
					}
					else if (c == "public")
					{
						fout(c, typeName, PUBLIC);
					}
					content.replace(0, 6, "");
					return true;
				}
			}
			else
				//六个字符之后无符号
			{
				if (c == "switch")
				{
					fout(c, typeName, SWITCH);
				}
				else if (c == "return")
				{
					fout(c, typeName, RETURN);
				}
				else if (c == "public")
				{
					fout(c, typeName, PUBLIC);
				}
				content = "";
				return true;
			}
		}
		if (content.size() >= 7)
		{
			c = content.substr(0, 7);
		}
		//单词只有六个字符，但不是关键字
		else
		{
			return false;
		}
		if ((c == "include") | (c == "private"))
		{
			if (content.size() >= 8)
			{
				if (((content[7] >= 'A') && (content[7] <= 'Z')) || ((content[7] >= 'a') && (content[7] <= 'z')) || ((content[7] >= '0') && (content[7] <= '9')) || (content[7] == '_'))
				{
					return false;
				}
				//七个字符之后有符号，但不是标识符
				else
				{
					if (c == "include")
					{
						fout(c, typeName, INCLUDE);
					}
					else if (c == "private")
					{
						fout(c, typeName, PRIVATE);
					}

					content.replace(0, 7, "");
					return true;
				}
			}
			else
				//七个字符之后无符号
			{

				if (c == "include")
				{
					fout(c, typeName, INCLUDE);
				}
				else if (c == "private")
				{
					fout(c, typeName, PRIVATE);
				}
				content = "";
				return true;
			}
		}
		if (content.size() >= 8)
		{
			c = content.substr(0, 8);
		}
		//单词只有七个字符，但不是关键字
		else
		{
			return false;
		}
		if ((c == "continue"))
		{
			if (content.size() >= 9)
			{
				if (((content[8] >= 'A') && (content[8] <= 'Z')) || ((content[8] >= 'a') && (content[8] <= 'z')) || ((content[8] >= '0') && (content[8] <= '9')) || (content[8] == '_'))
				{
					return false;
				}
				//八个字符之后有符号，但不是标识符
				else
				{
					fout(c, typeName, CONTINUE);
					content.replace(0, 7, "");
					return true;
				}
			}
			else
				//八个字符之后无符号
			{

				fout(c, typeName, CONTINUE);
				content = "";
				return true;
			}
		}
		if (content.size() >= 9)
		{
			c = content.substr(0, 9);
		}
		//单词只有八个字符，但不是关键字
		else
		{
			return false;
		}
		if ((c == "namespace") | (c == "protected"))
		{
			if (content.size() >= 10)
			{
				if (((content[9] >= 'A') && (content[9] <= 'Z')) ||( (content[9] >= 'a') && (content[9] >= 'z')) ||( (content[9] >= '0') && (content[9] <= '9')) || (content[9] == '_'))
				{
					return false;
				}
				//九个字符之后有符号，但不是标识符
				else
				{
					if (c == "namespace")
					{
						fout(c, typeName, NAMESPACE);
					}
					else if (c == "protected")
					{
						fout(c, typeName, PROTECTED);
					}

					content.replace(0, 9, "");
					return true;
				}
			}
			else
				//九个字符之后无符号
			{

				if (c == "namespace")
				{
					fout(c, typeName, NAMESPACE);
				}
				else if (c == "protected")
				{
					fout(c, typeName, PROTECTED);
				}
				content = "";
				return true;
			}
		}
		//字符串长度大于十，但未被识别，退出。
		if (content.size() >= 9)
		{
			return false;

		}

		return false;
	}