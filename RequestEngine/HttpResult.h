#pragma once
class HttpResult
{
private:

	unique_ptr<string> content;
	int resultCode;

public:
	HttpResult(void);
	~HttpResult(void);

	bool isSucessful()
	{
		return resultCode / 100 == 2;
	}
};

