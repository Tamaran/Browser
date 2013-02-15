#include "StdAfx.h"
#include "DomParser.h"


string DomParser::CLOSING_BRACKET(">");
string DomParser::OPENING_BRACKET("<");
string DomParser::EXCLAMATION("!");
string DomParser::SLASH("/");

DomParser::DomParser(HtmlTokenizer* t) : tok(unique_ptr<HtmlTokenizer>(t))
{
	parseDocument();	
}


DomParser::~DomParser(void)
{
}

DomNode* DomParser::getRoot()
{
	return NULL;
}

DomNode* DomParser::parseElementList(shared_ptr<string> endElement)
{
	DomNode* node = new DomNode();
	node->setTag(endElement);
	debug_print("parseElementList of ");
	debug_print(endElement->c_str());
	debug_print("\n");
	HtmlTokenizer& t = *tok;
	while(true)
	{
		noFileEnd();
		if(t.get()->compare(OPENING_BRACKET) == 0)
		{
			t.moveNext();
			noFileEnd();
			shared_ptr<string> str = t.get();
			//Ist ein endtag, und sollte diese liste schließen
			if(str->compare(SLASH) == 0)
			{
				t.moveNext();
				expect(*endElement);
				t.moveNext();
				expect(CLOSING_BRACKET);
				t.moveNext();
				return node;
			}
			//ist ein kommentar	
			if(str->compare(EXCLAMATION) == 0)
			{
				skipTag();
				continue;
			}
			//ist ein opentag
			t.moveNext();
			expect(CLOSING_BRACKET);
			t.moveNext();
			node->addChild(parseElementList(str));
		}
		else
		{
			debug_print(endElement->c_str());
			debug_print(" text content: ");
			debug_print(t.get()->c_str());
			debug_print("\n");
			node->setText(t.get());
			t.moveNext();
		}
	}
}

void DomParser::parseElement(string& e)
{
	debug_print("parseElement: ");
	debug_print(e.c_str());
	debug_print("\n");

}

void DomParser::parseDocument()
{
	debug_print("parseDocument\n");
	skipTag();
	skipTag();
	parseElementList(shared_ptr<string>(new string("html")));
}

void DomParser::readHead()
{
	debug_print("readHead\n");
}

void DomParser::readBody()
{
	debug_print("readBody\n");
}

void DomParser::parseDoctype()
{
	debug_print("parseDoctype\n");
}

void DomParser::skipTag()
{
	debug_print("skipTag\n");
	shared_ptr<string> e;
	while((e = tok->get()) != NULL && e->compare(CLOSING_BRACKET) != 0)
	{
		tok->moveNext();
	}
	tok->moveNext();
}


void DomParser::expect(string& str)
{
	shared_ptr<string> e = tok->get();
	if(e == NULL || e->compare(str) != 0)
	{
		stringstream ss;
		if(e == NULL)
		{
			ss << "Unexpected end of file: " << str << " expected";
		}
		else
		{
			ss << str << " expected at line " << tok->getLine();
		}
		throw SyntaxException(new string(ss.str()));
	}
}

void DomParser::noFileEnd()
{
	if(tok->get() == NULL)
	{
		throw SyntaxException(new string("Unexpected end of file"));
	}
}


