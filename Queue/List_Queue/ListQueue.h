#pragma once

typedef int myType;

struct Node
{
	myType Data;
	Node *pNext;
};

class ListQueue
{
private:
	Node *pHead;
	Node *pTail;
public:
	ListQueue();
	~ListQueue();

	void EnQueue(myType data);
	myType DeQueue();
};