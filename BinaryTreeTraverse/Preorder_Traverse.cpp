#include<iostream>
using namespace std;

typedef int myType;

struct Node
{
	myType data;
	Node *pleft;
	Node *pRight;
};

Node *pHead, *pTail;

void Init()
{
	pHead->pleft = pTail;
	pHead->pRight = pTail;
	pTail->pleft = pTail;
	pTail->pRight = pTail;
}

void visit(Node *pTemp)
{
	cout<<pTemp->Data<<endl;
}

void RecursivePreorderTraverse(Node *pTemp)
{
	if(pTemp != pTail)
	{
		visit(pTemp);
		RecursivePreorderTraverse(pTemp->pleft);
		RecursivePreorderTraverse(pTemp->pRight);
	}
}


//better performing

//false sample stack
void Push(Node *pTemp);
Node *Pop();
void InitStack();
bool IsStackEmpty();

void StackPreorderTraverse(Node *pTemp)
{
	InitStack();
	push(pTemp);

	while(!IsStackEmpty())
	{
		pTemp = pop();
		
		visit(pTemp);

		if(pTemp != pTail)
			push(pTemp->pRight);

		if(pTemp != pTail)
			push(pTemp->pleft);
	}
}
