#pragma once
#define MAX			100

typedef int myType;

class ArrayQueue
{
private:
	myType Queue[MAX];
	int Front;
	int Rear;
public:
	ArrayQueue();
	~ArrayQueue();

	void EnQueue(myType data);
	myType DeQueue();
};
