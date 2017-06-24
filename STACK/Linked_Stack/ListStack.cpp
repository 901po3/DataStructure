#include"ListStack.h"

ListStack::ListStack()
{
	pHead = new Node;
	pTail = new Node;
	pHead->pNext = pTail;
	pTail->pNext = pTail;
}

ListStack::~ListStack()
{

}

void ListStack::Push(myType data)
{
	Node *pTemp;
	pTemp->Data = data;
	pHead->pNext = pTemp->pNext;
	pHead->pNext = pTemp;
}

myType ListStack::Pop()
{
	if(pHead->pNext == pTail)
		return;
	Node* pTemp = pHead->pNext;
	pHead->pNext = pHead->pNext->pNext;
	int temp = pTemp->Data;
	delete pTemp;
	return temp;
}

myType ListStack::Peek()
{
	return pHead->pNext->Data;
}

