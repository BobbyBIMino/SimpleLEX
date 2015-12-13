#include "stdafx.h"
#include "statement.h"

Statement::Statement()
{
	typeName = "Statement";
}

bool Statement::phrase(string& content)
{
	if (content == "int")
	{
		fout(content, typeName, INT);
	}
	else if (content == "static") {
		fout(content, typeName, STATIC);
	}
	else if (content == "const") {
		fout(content, typeName, CONST);
	}
	else if (content == "unsigned") {
		fout(content, typeName, UNSIGNED);
	}
	else if (content == "double") {
		fout(content, typeName, DOUBLE);
	}
	else if (content == "float") {
		fout(content, typeName, FLOAT);
	}
	else if (content == "bool") {
		fout(content, typeName, BOOL);
	}
	else if (content == "void") {
		fout(content, typeName, VOID);
	}
	else if (content == "inline") {
		fout(content, typeName, INLINE);
	}
	else if (content == "friend") {
		fout(content, typeName, FRIEND);
	}
	else if (content == "new") {
		fout(content, typeName, NEW);
	}
	else if (content == "virual") {
		fout(content, typeName, VIRTUAL);
	}
	else {
		return false;
	}
	content = "";
	return true;
}
