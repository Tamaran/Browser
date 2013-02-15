#pragma once

#include "stdafx.h"

class HtmlTokenizer
{
private:


	unique_ptr<string> text;
	shared_ptr<string> nextElement;
	size_t i;

public:
	HtmlTokenizer(string* e);
	
	~HtmlTokenizer(void);

	shared_ptr<string> get();
	void moveNext();

	size_t getIndex()
	{
		return i;
	}

	size_t getLine();

private:

	HtmlTokenizer(const HtmlTokenizer&){};

	bool isWhitespace(char c);
	bool tryReadControlSymbol();

	void moveIndex();

};

