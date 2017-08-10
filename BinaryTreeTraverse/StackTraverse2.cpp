#include <iostream>
using namespace std;

struct BtreeNode
{
	char ch;
	BtreeNode *pLeft;
	BtreeNode *pRight;
};

typedef BtreeNode *myType;

struct Node
{
	myType Data;
	Node *pNext;
};

class ListStack
{
private:
	Node *pHead;
	Node *pTail;
public:
	ListStack();
	~ListStack() {}

	void Push(myType data);
	myType Pop();
	myType Peek();

	bool isStackEmpty() { return pHead->pNext == pTail ? true : false; }
};

ListStack::ListStack()
{
	pHead = new Node;
	pTail = new Node;
	pHead->pNext = pTail;
	pTail->pNext = pTail;
}

void ListStack::Push(myType data)
{
	Node *pTemp = new Node;
	pTemp->Data = data;
	pTemp->pNext = pHead->pNext;
	pHead->pNext = pTemp;
}

myType ListStack::Pop()
{
	if (pHead->pNext == pTail)
		return NULL;
	Node *pTemp = pHead->pNext;
	pHead->pNext = pTemp->pNext;
	myType temp = pTemp->Data;
	delete pTemp;
	return temp;
}

myType ListStack::Peek()
{
	return pHead->pNext->Data;
}

//////////////////////////////////////////////////

#define MAX_VERTEX		100

BtreeNode *G_Tree[MAX_VERTEX];

void SetTree()
{
	for (int i = 0; i < 9; i++)
	{
		G_Tree[i] = new BtreeNode;
		G_Tree[i]->ch = 'A' + i;
		G_Tree[i]->pLeft = NULL;
		G_Tree[i]->pRight = NULL;
	}

	G_Tree[0]->pLeft = G_Tree[1];
	G_Tree[1]->pLeft = G_Tree[3];
	G_Tree[2]->pLeft = G_Tree[4];
	G_Tree[6]->pLeft = G_Tree[7];

	G_Tree[0]->pRight = G_Tree[2];
	G_Tree[2]->pRight = G_Tree[5];
	G_Tree[5]->pRight = G_Tree[6];
	G_Tree[6]->pRight = G_Tree[8];
}

void Visit(BtreeNode *pNode)
{
	cout << pNode->ch << "  ";
}

void PreorderTraverse(BtreeNode *pRoot) //ABDCEFG
{
	ListStack stack;	
	BtreeNode *pTemp;

	stack.Push(pRoot);
	
	while (!stack.isStackEmpty())
	{
		pTemp = stack.Pop();
		if (pTemp == NULL) continue;
		Visit(pTemp);

		stack.Push(pTemp->pRight);
		stack.Push(pTemp->pLeft);
	}

	cout << endl;
}

void InorderTraverse(BtreeNode *pRoot) //DBAECFG
{
	ListStack stack;
	BtreeNode *pTemp;
	bool wentRight = true;

	stack.Push(pRoot);

	while (!stack.isStackEmpty())
	{
		while (stack.Peek()->pLeft != NULL && wentRight)
		{
			stack.Push(stack.Peek()->pLeft);
		}
		
		pTemp = stack.Pop();
		Visit(pTemp);
		wentRight = false;

		if (pTemp->pRight != NULL && !wentRight)
		{
			stack.Push(pTemp->pRight);
			wentRight = true;
		}
	}

	cout << endl;
}

void PostorderTraverse(BtreeNode *pRoot) //DBEGFCA
{
	ListStack stack;
	BtreeNode *pTemp;
	bool wentRight = true;
	bool putRight = false;
	stack.Push(pRoot);

	while (!stack.isStackEmpty())
	{
		while (stack.Peek()->pLeft != NULL && wentRight)
		{
			stack.Push(stack.Peek()->pLeft);
			putRight = false;
		}

		wentRight = false;

		if (stack.Peek()->pRight != NULL && !putRight)
		{
			stack.Push(stack.Peek()->pRight);
			wentRight = true;

			if(stack.Peek()->pRight == NULL) putRight = true;
		}	

		if (!wentRight)
		{
			pTemp = stack.Pop();
			Visit(pTemp);
		}
	}

	cout << endl;
}


int main()
{
	SetTree();

	PreorderTraverse(G_Tree[0]);
	InorderTraverse(G_Tree[0]);
	PostorderTraverse(G_Tree[0]);

	return 0;
}