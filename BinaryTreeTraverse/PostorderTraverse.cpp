#include<iostream>
using namespace std;

typedef int myType;

struct Node
{
	myType Data;
	Node *pLeft;
	Node *pRight;
};
Node *pHead, *pTail;

void Visit(Node *pTmep)
{
	cout<<pTemp->Data<<endl;
}

void RecursivePostorderTraverse(Node *pTemp)
{
	if(pTemp != pTail)
	{
		RecursivePreorderTraverse(pTemp->pleft);
		RecursivePreorderTraverse(pTemp->pRight);
		visit(pTemp);
	}
}

//better performing

//false sample stack
void Push(Node *pTemp);
Node *Pop();
void InitStack();
bool IsStackEmpty();


void StackPostorderTraverse(Node *pTemp)
{
	bool finished = false;
	Node *pSave;
	InitStack();

	while(!finished)
	{
		while(pTemp != pTail)
		{
			Push(pTemp);
			pTemp = pTemp->pLeft;
		}
		while(!IsStackEmpty())
		{
			pSave = pTemp;
			pTemp = Pop();
			if(pTemp->pRight != pTail)
			{
				if(pTemp->pRight == pSave)
					Visit(pTemp);
				else
				{
					Push(pTemp);
					pTemp = pTemp->pRight;
					break;
				}
			}
			else
				Visit(pTemp);
		}
		if(IsStackEmpty())
			finished = 1;
	}
}
