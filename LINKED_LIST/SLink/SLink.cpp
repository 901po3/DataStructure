#include"SLink.h"

SLink::SLink()
{
	pHead = new Node;
	pTail = new Node;
	pHead->pNext = pTail;
	pTail->pNext = pTail;
	int Count = 0;
}

SLink::~SLink()
{
	DeleteAllNode();
	if(pHead != NULL && pTail != NULL)
	{
		delete pHead;
		delete pTail;
	}
}

void SLink::CreateNode(myType data)
{
	Node *pTemp = new Node;
	pTemp->Data = data;

	pTemp->pNext = pHead->pNext;
	pHead->pNext = pTemp;
	Count++;
}

bool SLink::InsertNodeSorted(myType data)
{
	Node *pTemp = new Node;
	pTemp->Data = data;

	Node *pSearch;
	for(pSearch = pHead->pNext; pSearch != pTail; pSearch = pTemp->pNext)
	{
		if(pTemp->Data > pSearch->Data && pTemp->Data < pSearch->pNext->Data)
		{
			pTemp->pNext = pSearch->pNext;
			pSearch->pNext = pTemp;
			Count++;
			return true;
		}
	}
	delete pTemp;
	return false;
}

bool SLink::DeleteNode(myType data)
{
	Node *pTemp;
	for(pTemp = pHead->pNext; pTemp != pTail; pTemp = pTemp->pNext)
	{
		if(pTemp->pNext->Data == data)
		{
			Node *pDelete = pTemp->pNext;
			pTemp->pNext = pTemp->pNext->pNext;
			delete pDelete;
			Count--;
			return true;
		}
	}
	return false;
}

void SLink::DeleteAllNode()
{
	Node *pTemp, *pDelete;
	for(pTemp = pHead->pNext; pTemp != pTail; pTemp = pTemp->pNext)
	{
		pDelete = pTemp;
		delete pDelete;
	}
	Count = 0;
	pHead->pNext = pTail;
	pTail->pNext = pTail;
}

bool SLink::IsEmpty()
{
	if(pHead->pNext == pTail)
		return true;
	else 
		return false;
}
