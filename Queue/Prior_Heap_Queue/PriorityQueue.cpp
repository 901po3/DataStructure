#include"PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
	increTime = 1;
	curSize = 0;
	HeapArray = new myType[INCREASE_SIZE];
	for (int i = 0; i < INCREASE_SIZE; i++)
		HeapArray[i] = NOT_USED;
}

PriorityQueue::~PriorityQueue()
{
	increTime = curSize = 0;
	delete[]HeapArray;
}

void PriorityQueue::EnQueue(myType data)
{
	int k = (curSize - 1) / 2;
	int c = curSize++;
	HeapArray[c] = data;

	while (true)
	{
		if (HeapArray[k] <= HeapArray[c]) 
			break;	
		else if (HeapArray[k] > HeapArray[c])
		{
			int temp = HeapArray[k];
			HeapArray[k] = HeapArray[c];
			HeapArray[c] = temp;
			c = k;
			k = (c - 1) / 2;		
		}
	}

	//배열 사이즈 관리 15의배수번 추가 될때마다 사이즈 늘림;
	//STL의 VECTOR에서 아이디어 얻음
	if (curSize >= (increTime * INCREASE_SIZE) - 1)
	{
		myType *pNewArray = new myType[++increTime * INCREASE_SIZE];
		for (int i = 0; i < increTime * INCREASE_SIZE; i++)
		{
			if (i <= ((increTime - 1) * INCREASE_SIZE))
				pNewArray[i] = HeapArray[i];
			else
				pNewArray[i] = NOT_USED;
		}
		myType *pTemp = HeapArray;
		HeapArray = pNewArray;
		delete[]pTemp;
	}
}

myType PriorityQueue::DeQueue()
{
	if (curSize == 0) return 0;
	int k = 0;
	int leftC, rightC, smallerC;

	HeapArray[k] = HeapArray[--curSize];
	HeapArray[curSize + 1] = NOT_USED;

	while (true)
	{
		leftC = k * 2 + 1;
		rightC = k * 2 + 2;

		if (HeapArray[leftC] == NOT_USED || HeapArray[rightC] == NOT_USED) break;

		smallerC = HeapArray[leftC] <= HeapArray[rightC] ? leftC : rightC;

		if (HeapArray[k] > HeapArray[smallerC])
		{
			int temp = HeapArray[k];
			HeapArray[k] = HeapArray[smallerC];
			HeapArray[smallerC] = temp;

			k = smallerC;
		}
		else
			break;
	}

	return 0;
}

bool PriorityQueue::IsQueueEmpty()
{
	return curSize == 0 ? true : false;
}
