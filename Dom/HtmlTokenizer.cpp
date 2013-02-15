#include "StdAfx.h"
#include "HtmlTokenizer.h"


HtmlTokenizer::HtmlTokenizer(string* s) : text(unique_ptr<string>(s)), i(0)
{
	moveNext();
}


HtmlTokenizer::~HtmlTokenizer(void)
{
}

shared_ptr<string> HtmlTokenizer::get()
{
	return nextElement;
}



void HtmlTokenizer::moveNext()
{
	size_t len = text->length();
	while(i < len && isWhitespace(text->at(i)))
	{
		i++;
	}
	if(i < len)
	{
		if(!tryReadControlSymbol())
		{
			stringstream res;
			char c;
			while(i < len && !((c = text->at(i)) == '>' || c == '<'))
			{
				res << c;
				i++;
			}
			nextElement = shared_ptr<string>(new string(res.str()));
		}
	}
	else
	{
		nextElement = NULL;
	}
}

bool HtmlTokenizer::tryReadControlSymbol()
{
	char c = text->at(i);
	switch(c)
	{
	case '<':
	case '>':
	case '/':
	case '!':
		nextElement = shared_ptr<string>(new string());
		nextElement->push_back(c);
		i++;
		return true;
	}
	return false;
}

bool HtmlTokenizer::isWhitespace(char c)
{
	switch(c)
	{
	case ' ':
	case '\n':
	case '\r':
		return true;
	}
	return false;
}

size_t HtmlTokenizer::getLine()
{
	size_t count = 0;
	size_t pos = 0;
	while((pos = text->find_first_of("\n", pos)))
	{
		if(pos == string::npos)
		{
			break;
		}
		pos++;
		count++;
	}
	return count;
}
