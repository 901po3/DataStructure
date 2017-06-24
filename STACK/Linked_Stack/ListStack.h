#pragma once

typedef int myType;

struct Node
{
	myType Data;
	Node *pNext;
};

class ListStack
{
private:
	Node *pHead;
	Node *pTail;
public:
	ListStack();
	~ListStack();

	void Push(myType data);
	myType Pop();
	myType Peek();

};