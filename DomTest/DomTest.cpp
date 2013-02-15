// DomTest.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "HtmlTokenizer.h"
#include "DomParser.h"

string html("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n"
								"<html>\n"
									"<head>\n"
										"<title>Titel der Webseite</title>\n"
										"<!-- weitere Kopfinformationen -->\n"
										"<!-- Kommentare werden im Browser nicht angezeigt. -->\n"
									"</head>\n"
									"<body>\n"
										"<p>Inhalt der Webseite</p>\n"
									"</body>\n"
								"</html>\n");

void tokenizerTest()
{
	HtmlTokenizer t(&html);
	shared_ptr<string> e;
	while(true)
	{
		e = t.get();
		t.moveNext();
		if(e == NULL)
		{
			break;
		}
		cout << *e << endl;
	}
	cin.get();
}

void DomParserTest()
{
	HtmlTokenizer *tok = new HtmlTokenizer(new string(html));
	try
	{
		DomParser p(tok);
		stringstream ss;
		p.getRoot()->dump(ss, 0);
		cout << ss.str() << endl;
		
	}
	catch(SyntaxException &e)
	{
		cout << e.what() << endl;
	}
	cin.get();
}

int main()
{
	DomParserTest();

	return 0;
}


