#pragma once

#define INCREASE_SIZE		15
#define NOT_USED			-1

typedef int myType;

//to parent node -> (k - 1) /2
//to left child node -> 2k + 1
//to right child node -> 2k + 2

//using heap
class PriorityQueue
{
private:
	myType *HeapArray;
	int curSize;
	int increTime;
public:
	PriorityQueue();
	~PriorityQueue();

	void EnQueue(myType data);
	myType DeQueue();
	bool IsQueueEmpty();
};