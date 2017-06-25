#include"ArrayQueue.h"
#include<iostream>
using namespace std;

ArrayQueue::ArrayQueue()
{
	memset(Queue, 0, MAX);
	Front = Rear = 0;
}

ArrayQueue::~ArrayQueue()
{

}

void ArrayQueue::EnQueue(myType data)
{
	if(Rear+1 % MAX == Front)
		return;

	Queue[Rear] = data;
	Rear = Rear++ % MAX;
}

myType ArrayQueue::DeQueue()
{
	if(Rear == Front)
		return 0;

	Front ++;
	return Queue[Front - 1];
	
}
