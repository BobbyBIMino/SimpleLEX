#include "stdafx.h"
#include "num.h"
/*
��дnumʱ������
*/
Num::Num()
{
	typeName = "Num";
}
bool Num::phrase(string& content)
{/*
	string c = "";
	//�ж��Ƿ�Ϊ�գ�����ǿվͿ���ֱ�ӷ���
	if (!content.empty())
	{
		c = content.substr(0, 4);
	}
	else
	{
		return false;
	}
	//ʶ��true��false�����ǵ�true��false����ֻ�ܸ�";"
	if (c == "true")
	{
		if (content.size() > 4)
		{
			if (content[4] != ';')
			{
				return false;
			}
		}
		//content.size==4��true�����Ƿֺ�
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
		//content.size==5��true�����Ƿֺ�
		fout(c, typeName, FALSE);
		content.replace(0, 5, "");
		return true;
	}
	c = "";
	//ʶ����
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
		//�ַ���δ�����������˳�����֮����ַ������ַ����������������num����
		else if ((content[i] == '+') || (content[i] == '-') || (content[i] == '*') || (content[i] == '/') || (content[i] == '%') || (content[i] == ',') || (content[i] == ';'))
		{
			break;
		}
		//��ʾ���ִ���ע��������ֶ����Ҳ��ʾ���ִ���
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

//��ʼ״̬
//���fng����1��ʾ�����˸��š�
bool fng = false;
	int state = 0;

	string c = "";
	//��¼��ǰ
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
			//�������֣���������һЩ�ָ���
			else if ((content[i] == '+') || (content[i] == '-') || (content[i] == '*') || (content[i] == '/') || (content[i] == '%') || (content[i] == ',') || (content[i] == ';')|| (content[i] == ')'))
			{
				state = 5;
			}
			//�ǵ㣬���Ϊ������
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
			//�ַ���β
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
			//�ַ���β
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