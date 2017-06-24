#include<iostream>
using namespace std;

#define MAX		100

struct Node
{
	char key;
	Node *pLeft;
	Node *pRight;
};

Node *Queue[MAX];

int Front, Rear;

void InitQueue()
{
	Front = Rear = 0;
}

int IsQueueEmpty()
{
	if(Rear == Front)
		return true;
	else
		return false;
}

void PutQueue(Node *ptrNode)
{
	if(Rear+1 % MAX == Front)
		return;

	Queue[Rear] = ptrNode;
	Rear = Rear++ % MAX;
}

Node *GetQueue()
{
	if(Rear == Front)
		return NULL;

	Node *ptrNode = Queue[Front];
	Front = Front++ % MAX;
	return ptrNode;
}


//////
void InitTree();
void MakeTree();
void LevelTraverse(Node *);
void Visit(Node *);

Node *pParent, *pLChild, *pRChild;
Node *pRoot, *pEnd;

void InitTree()
{
	pRoot			= new Node;
	pEnd				= new Node;

	pRoot->pLeft		= pEnd;
	pRoot->pRight		= pEnd;

	pEnd->pLeft		= pEnd;
	pEnd->pRight		= pEnd;
}

void MakeTree()
{
	pParent			= new Node;
	pParent->key		= 'A';

	pLChild			= new Node;
	pLChild->key		= 'B';

	pRChild			= new Node;
	pRChild->key		= 'C';

	pParent->pLeft	= pLChild;
	pParent->pRight	= pRChild;
	
	pRoot->pLeft		= pParent;
	pRoot->pRight		= pParent;

	pParent			= pParent->pLeft;

	pLChild			= new Node;
	pLChild->key		= 'D';
	pLChild->pLeft	= pEnd;
	pLChild->pRight	= pEnd;

	pRChild			= new Node;
	pRChild->key		= 'E';
	pRChild->pLeft	= pEnd;
	pRChild->pRight	= pEnd;

	pParent->pLeft	= pLChild;
	pParent->pRight	= pRChild;
	pParent			= pRoot->pRight->pRight;

	pLChild			= new Node;
	pLChild->key		= 'F';
	pLChild->pLeft	= pEnd;
	pLChild->pRight	= pEnd;

	pRChild			= new Node;
	pRChild->key		= 'G';
	pRChild->pLeft	= pEnd;
	pRChild->pRight	= pEnd;

	pParent->pLeft	= pLChild;
	pParent->pRight	= pRChild;

}

void LevelTraverse(Node *ptrNode)
{
	PutQueue(ptrNode);
	
	while(!IsQueueEmpty())
	{
		ptrNode	= GetQueue();

		Visit(ptrNode);

		if(ptrNode->pLeft != pEnd)
			PutQueue(ptrNode->pLeft);

		if(ptrNode->pRight != pEnd)
			PutQueue(ptrNode->pRight);
	}

}

void Visit(Node *ptrNode)
{
	cout<<ptrNode->key<<" -> ";
}

void main()
{
	InitQueue();
	InitTree();

	MakeTree();

	LevelTraverse(pRoot->pLeft);
}