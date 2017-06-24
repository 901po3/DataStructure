#include"ListQueue.h"

ListQueue::ListQueue()
{
	pHead = new Node;
	pTail = new Node;
	pHead->pNext = pTail;
	pTail->pNext = pTail;
}

ListQueue::~ListQueue()
{

}

void ListQueue::EnQueue(myType data)
{
	Node *pTemp = new Node;
	pTemp->Data = data;
	if(pHead->pNext == pTail)
	{
		pTemp->pNext = pHead->pNext;
		pHead->pNext = pTemp;
	}
	else
	{
		pTemp->pNext = pTail;
		pTail->pNext = pTemp;
	}

	pTail = pTemp;
}

myType ListQueue::DeQueue()
{
	Node *pTemp = pHead->pNext;
	myType temp = pTemp->Data;
	pHead->pNext = pTemp->pNext;
	delete pTemp;
	return temp;
}