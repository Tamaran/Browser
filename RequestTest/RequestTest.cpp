// RequestTest.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include "HttpRequest.h"



int main()
{
	try
	{
		string url("www.google.de");
		HttpRequest req;
		req.query(url);
		
	}
	catch(exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}
	cin.get();
	return 0;
}

