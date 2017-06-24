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

void visit(Node* pTemp)
{
	cout<<pTemp->Data<<endl;
}

void RecursiveInorderTraverse(Node *pTemp)
{
	if(pTemp != pTail)
	{
		RecursiveInorderTraverse(pTemp->pLeft);
		visit(pTemp);
		RecursiveInorderTraverse(pTemp->pRight);
	}
}


//better performing

//false sample stack
void Push(Node *pTemp);
Node *Pop();
void InitStack();
bool IsStackEmpty();

void StackInorderTraverse2(Node *pTemp)
{
	bool finished = false;
	InitStack();

	while(!finished)
	{
		while(pTemp != pTail)
		{
			Push(pTemp->pLeft);
		}
		if(!IsStackEmpty())
		{
			pTemp = Pop();
			visit(pTemp);
			Push(pTemp->pRight);
		}
		else
			finished = true;
	}
}