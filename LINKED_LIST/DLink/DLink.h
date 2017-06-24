#pragma once

typedef int myType;

struct Node
{
	myType Data;
	Node *pNext;
	Node *pPrev;
};

class DLink
{
private:
	Node *pHead;
	Node *pTail;
public:
	DLink();
	~DLink();

	void CreateNode(myType data);

	bool DeleteNode(myType data);

	void DeleteAllNode();
};