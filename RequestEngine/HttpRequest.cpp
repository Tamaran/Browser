#include "StdAfx.h"
#include "HttpRequest.h"

HttpRequest::HttpRequest(void)
{
}

DomNode* HttpRequest::query(const string &url)
{
	boost::system::error_code error;

	io_service ioservice;
	ip::tcp::socket* socket = createSocket(url, ioservice);
	sendRequest(*socket, url);
	string* response = getResponse(*socket);

	cout << *response << endl;
	socket->close();
	return NULL;
}

ip::tcp::socket* HttpRequest::createSocket(const string &url, io_service &ioservice)
{
	boost::system::error_code error = boost::asio::error::host_not_found;

	ip::tcp::socket* socket = new ip::tcp::socket(ioservice);
	
	ip::tcp::resolver resolver(ioservice);
	ip::tcp::resolver::query query(url.c_str(), "http");
	ip::tcp::resolver::iterator it = resolver.resolve(query);
	ip::tcp::resolver::iterator end;

	while(error && it != end)
	{
		socket->close();
		socket->connect(*it, error);
	}
	if(error)
	{
		throw boost::system::system_error(error);
	}
	return socket;
}

void HttpRequest::sendRequest(ip::tcp::socket& socket, const string& url)
{
	boost::system::error_code error;
	boost::asio::streambuf request;
	ostream request_stream(&request);
	request_stream << generateQuery();
	write(socket, request, boost::asio::transfer_all(), error);
}

string* HttpRequest::getResponse(ip::tcp::socket& socket)
{
	boost::system::error_code error;
	boost::asio::streambuf response;
	size_t len = read(socket, response, transfer_all(), error);
	boost::asio::streambuf::const_buffers_type buf = response.data();
	return new string(buffers_begin(buf), buffers_begin(buf)+len);
}


char* HttpRequest::generateQuery(const string& url)
{
	return "GET infotext.html HTTP/1.1\r\n"
			"Host: www.example.net\r\n"
			"Accept: */*\r\n"
			"Connection: close\r\n\r\n";
}