#include "stdafx.h"
#include "error.h"

Error::Error()
{
	typeName = "error";
}

bool Error::phrase(string & content)
{
	fout(content, typeName, 1);
	content.replace(0, content.size(), "");

	return false;
}
