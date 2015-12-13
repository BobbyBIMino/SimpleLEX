// Compiler1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "assignment.h"
#include "base.h"
#include "error.h"
#include "keyword.h"
#include "operation.h"
#include "separator.h"
#include "statement.h"
#include "num.h"
#include "id.h"
#include "note.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{	Assignment ass;

	Error err;
	Separator  se;
	Id id;
	Statement state;
	Operation op;
	Num num;
	Keyword keyword;
	Note note;
	//�����һ��ѭ������û�б�ʶ��
	bool seF = false;
	bool assF = false;
	bool idF = false;
	bool stateF = false;
	bool opF = false;
	bool numF = false;
	bool keywordF = false;


	ifstream in("in.txt");

	string content;
	string cc;
	in >> content;
	int stateZ = 0;
	while (!in.eof())
	{
		switch (stateZ)
		{
			//��ʼ״̬
		case 0:
			seF = false;
			assF = false;
			idF = false;
			stateF = false;
			opF = false;
			numF = false;
			keywordF = false;
			if (content.size() == 0)
			{
				stateZ = 0;
				in >> content;
			}/*
			 //ע��"//"����
			else if (content.substr(0, 2) == "//")
			{
				stateZ = 1;
			}
			//ע�͡�/*���Ĵ���
			else if (content.substr(0, 2) == "/*")
			{
				stateZ = 2;
			}*/
			else
			{
				stateZ = 3;
			}
			break;/*
		case 1:
			getline(in, cc);
			content = content + cc;
			note.phrase(content);
			stateZ = 0;
			break;
		case 2:
			getline(in, cc);
			content = content + cc;
			while (cc == "")
			{
				getline(in, cc);
				content = content + cc;
			}
			while (cc.find("*//*") != -1)
			{
				getline(in, cc);
				content = content + cc;
			}
			note.phrase(content);
			stateZ = 0;
			break;*/
		case 3:
			keywordF = keyword.phrase(content);
			if (!keywordF)
			{
				stateZ = 4;
			}
			else if (keywordF)
			{
				stateZ = 0;
			}
			break;
		case 4:
			stateF = state.phrase(content);
			if (!stateF)
			{
				stateZ = 5;
			}
			else if (stateF)
			{
				stateZ = 0;
			}
			break;
		case 5:
			opF = op.phrase(content);
			if (!opF)
			{
				stateZ = 6;
			}
			else if (opF)
			{
				stateZ = 0;
			}

			break;
		case 6:
			seF = se.phrase(content);
			if (!seF)
			{
				stateZ = 7;
			}
			else if (seF)
			{
				stateZ = 0;
			}
			break;
		case 7:
			assF = ass.phrase(content);
			if (!assF)
			{
				stateZ = 8;
			}
			else if (assF)
			{
				stateZ = 0;
			}
			break;
		case 8:
			numF = num.phrase(content);
			if (!numF)
			{
				stateZ = 9;
			}
			else if (numF)
			{
				stateZ = 0;
			}
			break;
		case 9:
			idF = id.phrase(content);
			if (!idF)
			{
				stateZ = 10;
			}
			else if (idF)
			{
				stateZ = 0;
			}
			break;
		case 10:
			err.phrase(content);
			stateZ = 0;
			break;


		}

		/*
			//ѭ������content
			{
			while (!content.empty())
			{
				 keywordF = keyword.phrase(content);
				 stateF = state.phrase(content);
				 if (stateF) continue;
				 opF = op.phrase(content);
				 if (opF) continue;
				 seF = se.phrase(content);
				 if (seF) continue;
				 assF= ass.phrase(content);
				 if (assF) continue;
				 numF= num.phrase(content);
				 if (numF) continue;
				 idF= id.phrase(content);
				 // content��Ϊ�յ������ȫΪһ����û�б���
				 if ((!(keywordF || stateF || seF || assF || opF || numF || idF))&&(!content.empty()))
				 {
					 //��һ��ֻ�ǽ��������
					 err.phrase(content);
				 }}
				 */





	}


	in.close();
}