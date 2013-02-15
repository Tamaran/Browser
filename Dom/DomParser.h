#pragma once

#include "stdafx.h"
#include "DomNode.h"
#include "HtmlTokenizer.h"
#include "SyntaxException.h"

class DomParser
{
private:
	unique_ptr<HtmlTokenizer> tok;

	static string CLOSING_BRACKET, 
				  OPENING_BRACKET, 
				  EXCLAMATION,
				  SLASH;

public:
	DomParser(HtmlTokenizer* t);
	~DomParser(void);

	DomNode* getRoot();

private:
	void parseDocument();
	DomNode* parseElementList(shared_ptr<string> endElement);
	void parseElement(string& e);
	void parseDoctype();
	void skipTag();
	void readHead();
	void readBody();

	void expect(string& str);
	void noFileEnd();
};


