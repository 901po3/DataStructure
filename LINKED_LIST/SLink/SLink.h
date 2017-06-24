#pragma once

typedef int myType;

struct Node
{
	myType Data;
	Node *pNext;
};

class SLink
{
private:
	Node *pHead;
	Node *pTail;
	int Count;
public:
	SLink();
	~SLink();

	void CreateNode(myType data);
	bool OrderlyInsertNode(myType data);

	bool DeleteNode(myType data);
	void DeleteAllNode();

	bool IsEmpty();
};