#include"DLink.h"
#include<iostream>
using namespace std;

DLink::DLink()
{
	pHead = new Node;
	pTail = new Node;
	pHead->pNext = pTail;
	pHead->pPrev = pHead;
	pTail->pNext = pTail;
	pTail->pPrev = pHead;
}

DLink::~DLink()
{
	DeleteAllNode();
	if(pHead!=NULL && pTail!=NULL)
	{
		delete pHead;
		delete pTail;
	}
}

void DLink::CreateNode(myType data)
{
	Node *pTemp = new Node;
	pTemp->Data = data;
	
	pTemp->pNext = pHead->pNext;
	pHead->pNext->pPrev = pTemp;
	pHead->pNext = pTemp;
	pTemp->pPrev = pHead;
}

bool DLink::DeleteNode(myType data)
{
	Node *pTemp;
	for(pTemp = pHead->pNext; pTemp!=pTail; pTemp = pTemp->pNext)
	{
		if(pTemp->Data == data)
		{
			Node *pDelete = pTemp;
			pTemp->pPrev->pNext = pTemp->pNext;
			pTemp->pNext->pPrev = pTemp->pPrev;
			delete pTemp;
			return true;
		}
	}
	return false;
}

void DLink::DeleteAllNode()
{
	Node *pTemp, *pDelete;
	for(pTemp = pHead->pNext; pTemp!=pTail; pTemp = pTemp->pNext)
	{
		pDelete = pTemp;
		delete pDelete;
	}
}