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
		//���ϵ�һ���ַ�
		c = c + content[0];
		if (content.size() > 1)
		{
			for (int i = 1;i < content.size(); i++)
			{
				if (((content[i] >= 'A') && (content[i] <= 'Z')) || ((content[i] >= 'a') && (content[i] <= 'z')) | ((content[i] >= '0') && (content[i] <= '9')) || (content[i] == '_'))
					//��i���ַ���Ȼ�Ǳ�ʶ���п��Գ��ֵ��ַ�
				{
					c = c + content[i];
				}
				//��������֮����ַ����ж��ǲ��Ƿָ�����op���ȷ���
				else if ((content[i] == '<') || (content[i] == '#') || (content[i] == '%') | (content[i] == '*') | (content[i] == '(') || (content[i] == '{') || (content[i] == '=') || (content[i] == '+') | (content[i] == '-') | (content[i] == '/') || (content[i] == '[') || (content[i] == '>') || (content[i] == '>') || (content[i] == '.') || (content[i] == '\"') || (content[i] == ';')|| (content[i] == ':')|| (content[i] == ')')|| (content[i] == ']')|| (content[i] == ','))
					//�˳�ѭ��
				{
					break;
				}
				else
					//��������֮����֣��������õķ���,ֱ�ӷ���
				{
					return false;
				}
			}
		}
		//c���е���ĸ���Ǳ�ʶ���п��Գ��ֵ��ַ���Ҫ��cд���ļ����ؼ������ȷ��c�ı�ţ���ͬһ���ļ��У�ͬһ����ʶ��Ӧ�ñ�ʶ��Ϊͬһ����
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
					//c�ѳ��ֹ������λ�ò�������ء�
					if (c == cont.at(i))
					{
						fout(c, typeName, i);
						content.replace(0, c.size(), "");
						return true;

					}
				}
			//cδ���֣�cѹ�������������
			cont.push_back(c);
			fout(c, typeName,cont.size()-1);
			content.replace(0, c.size(), "");
			return true;
		}

	}
	else
		//��һ���ַ�������Ҫ�󣬷���
	{
		return false;



	}
}
*/
{	//��ʼ״̬
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
				state = 3;
			}
			else if (((content[i] >= 'A') && (content[i] < 'Z')) || ((content[i] >= 'a') && (content[i] <= 'z')) | (content[i] == '_'))
			{
				c = c + content[i];
				state = 1;
			}
			else
				//��һ���ַ����Ϸ����˳���
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
			//���治�Ǳ�ʶ���пɳ��ֵ��ַ������Ǳ�ʶ����������ֵ��ַ������������ñ�ʶ��	
			else 	if ((content[i] == '<') || (content[i] == '#') || (content[i] == '%') | (content[i] == '*') | (content[i] == '(') || (content[i] == '{') || (content[i] == '=') || (content[i] == '+') | (content[i] == '-') | (content[i] == '/') || (content[i] == '[') || (content[i] == '>') || (content[i] == '>') || (content[i] == '.') || (content[i] == '\"') || (content[i] == ';') || (content[i] == ':') || (content[i] == ')') || (content[i] == ']') || (content[i] == ','))
			{
				state = 2;
			}
			else {
				state = 3;
			}
			break;
		case 2:
			//����ַ���������״̬��
			//c���е���ĸ���Ǳ�ʶ���п��Գ��ֵ��ַ���Ҫ��cд���ļ����ؼ������ȷ��c�ı�ţ���ͬһ���ļ��У�ͬһ����ʶ��Ӧ�ñ�ʶ��Ϊͬһ����
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
					//c�ѳ��ֹ������λ�ò�������ء�
					if (c == cont.at(i))
					{
						fout(c, typeName, i);
						content.replace(0, c.size(), "");
						return true;
					}
				}
				//cδ���֣�cѹ�������������
				cont.push_back(c);
				fout(c, typeName, cont.size() - 1);
				content.replace(0, c.size(), "");
				return true;
			}
				break;
		case 3:
			//��ʶ�����Ϸ�
			return false;
			break;

		}

	}
}