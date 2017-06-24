#pragma once
#define MAX		100

typedef int myType;

class ArrayStack
{
private:
	myType Stack[MAX];
	int Top;
public:
	ArrayStack();
	~ArrayStack();

	void Push(myType data);
	myType Pop();
	bool IsStackEmpty();
};