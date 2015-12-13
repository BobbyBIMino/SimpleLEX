#include "stdafx.h"
#include "note.h"

Note::Note()
{
	typeName = "Note";
}

bool Note::phrase(string & content)
{
	if (content.substr(0, 2) == "//")
		fout(content, typeName, HANG);
	else 
		fout(content, typeName, DUAN);
	content.replace(0, content.size(), "");
	return false;
}
