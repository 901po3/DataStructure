#include <iostream>
#include "ArrayStack.h"
#include "common.h"
using namespace std;

void SetCountOutdegree(Head net[], int V)
{
	int count;
	Node *pTemp;
	for (int i = 0; i < V; i++)
	{
		count = 0;
		for (pTemp = net[i].pNext; pTemp != NULL; pTemp = pTemp->pNext)
			count++;
		net[i].count = count;
	}
}

void ReverseTopologicalSort(Head net[], int V) //거꾸로 출력
{
	ArrayStack stack;

	for (int i = 0; i < V; i++)
		if (!net[i].count) stack.Push(i);

	for (int i = 0; i < V; i++)
	{
		if (stack.IsStackEmpty())
		{
			printf("\nNetwork has a cylce. Sort Terminated ! ");
			exit(1);
		}
		else
		{
			int j = stack.Pop();
			printf("%c, ", int2name(j));
			for (int k = 0; k < V; k++)
			{
				for (Node *pTemp = net[k].pNext; pTemp != NULL; pTemp = pTemp->pNext)
				{
					if (pTemp->vertex == j)
					{
						net[k].count--;
						if (!net[k].count)
							stack.Push(k);
					}
				}
			}
		}
	}
}

