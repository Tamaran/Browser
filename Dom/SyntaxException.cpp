#include "stdafx.h"
#include "SyntaxException.h"

SyntaxException::SyntaxException(string *s) : msg(unique_ptr<string>(s))
{

}

SyntaxException::~SyntaxException(void)
{

}

const char* SyntaxException::what()
{
	return msg->c_str();
}