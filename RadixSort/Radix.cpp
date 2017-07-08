#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

#define MAX			10
#define TRUE			true
#define FALSE			false

struct Node
{
	int Data;
	Node *pNext;
};

Node *Front[10];
Node *Rear[10];
Node *ptrNode;
int buf[MAX];

void MakeRandomNumber();
void RadixSort();
void DisplayBuffer();
int IsNumberExit(int, int);
void InitializeQueue();
void Put(int, int);
int Get(int);

void MakeRandomNumber()
{
	int i, num;
	i = 0;
	srand((unsigned) time (NULL));

	while(i < MAX)
	{
		num = rand() % 100;

		if(!IsNumberExit(num, i))
		{
			buf[i] = num;
			i++;
		}
	}
}

void DisplayBuffer()
{
	int i;

	for(i = 0; i < MAX; i++)
	{
		if((i % 10) == 0)
			cout<<endl;

		cout<<buf[i]<<"	";
	}
	cout<<endl;
}

int IsNumberExit(int number, int index)
{
	int i;
	for(i = 0; i < index; i++)
	{
		if(buf[i] == number)
			return TRUE;
	}
	return FALSE;
}

void InitializeQueue()
{
	int i;
	for(i = 0; i < MAX; i++)
	{
		Front[i]			= new Node;
		Rear[i]			= new Node;
		Front[i]->pNext	= Rear[i];
		Rear[i]->pNext	= Rear[i];
	}
}

void Put(int index, int num)
{
	ptrNode = new Node;
	ptrNode->Data = num;

	if(Front[index]->pNext == Rear[index])
	{
		Front[index]->pNext = ptrNode;
		ptrNode->pNext = Rear[index];
		Rear[index]->pNext = ptrNode;
	}
	else
	{
		Rear[index]->pNext->pNext = ptrNode;
		ptrNode->pNext = Rear[index];
		Rear[index]->pNext = ptrNode;
	}
}

int Get(int index)
{
	int ret;
	Node *pDeleteNode;

	if(Front[index]->pNext == Rear[index])
		return -1;

	else
	{
		pDeleteNode = Front[index]->pNext;
		Front[index]->pNext = pDeleteNode->pNext;
		ret = pDeleteNode->Data;

		delete pDeleteNode;
	}
	return ret;
}

void RadixSort()
{
	int i, num, digit, j;
	j = 0;


	//1의 자릿수로 정렬
	for(i = 0; i < MAX; i++)
	{
		num = buf[i];
		digit = num % MAX;
		Put(digit, num);
	}

	cout<<endl<<"1의 자릿수로 정렬된 숫자 리스트"<<endl;

	for(i = 0; i < MAX; i++)
	{
		cout<<endl<<i<<"의 자리 : ";

		while(1)
		{
			num = Get(i);
			if(num != -1)
			{
				cout<<num<<"	";
				buf[j++] = num;
			}
			else 
				break;
		}
	}

	cout<<endl<<endl<<"2차 정렬 후 buf 안 데이터들"<<endl;

}

void main()
{
	InitializeQueue();
	cout<<"정렬할 데이터 초기화\n";

	MakeRandomNumber();
	DisplayBuffer();
	RadixSort();
	DisplayBuffer();

	cout<<endl<<endl<<endl;
}