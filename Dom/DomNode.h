#pragma once

#include "stdafx.h"

class DomNode
{

private:

	vector<unique_ptr<DomNode>> childs;
	shared_ptr<string> text;
	shared_ptr<string> tag;

public:

	void setTag(shared_ptr<string> str)
	{
		tag = str;
	}

	void setText(shared_ptr<string> str)
	{
		text = str;
	}

	void addChild(DomNode* node)
	{
		childs.push_back(unique_ptr<DomNode>(node));
	}

	void dump(stringstream &ss, int depth)
	{
		for(int i = 0; i < depth; i++)
		{
			ss << "\t";
		}
		ss << tag << endl;
	}

public:
	DomNode(void);
	~DomNode(void);
};

