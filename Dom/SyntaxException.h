#pragma once

#include "stdafx.h"

class SyntaxException : public exception
{

private:

	unique_ptr<string> msg;

public:

	SyntaxException(string *s);

	~SyntaxException(void);

	const char* what();

private:

	SyntaxException(const SyntaxException&){}
};

