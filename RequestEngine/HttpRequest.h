#pragma once

#include "stdafx.h"
#include "DomNode.h"

using namespace boost::asio;

class HttpRequest
{
private:

	

public:
	HttpRequest(void);
	
	DomNode* query(const string &url);

private:

	HttpRequest(const HttpRequest&){}
	ip::tcp::socket* createSocket(const string &url, io_service &ioservice);

	void sendRequest(ip::tcp::socket& socket, const string& url);
	string* getResponse(ip::tcp::socket& socket);

	char* generateQuery(const string& url);
};

