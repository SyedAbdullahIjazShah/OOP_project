#include"Post.h"
class sharememory
{
public:
	sharememory();
	~sharememory();

private:
	Post* memory;
	string memorycontent;
};

sharememory::sharememory()
{
}

sharememory::~sharememory()
{
}
#pragma once
