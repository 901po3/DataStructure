#include <iostream>
#include "ArrayStack.h"
#include "common.h"
using namespace std;

void SetCountIndegree(Head net[], int V)
{
	int i, j;
	Node *pTemp;
	int count;
	for (i = 0; i < V; i++) // i is a vertex where current indegree is heading to.
	{
		count = 0;
		for (j = 0; j < V; j++) //net[j]is destination index of indegree j; 
			for (pTemp = net[j].pNext; pTemp != NULL; pTemp = pTemp)
				if (pTemp->vertex == i) count++; //if j == i means j is heading to i
		net[i].count = count;
	}
}

void TopologicalSort(Head net[], int V)
{
	Node *pTemp;
	ArrayStack stack;

	SetCountIndegree(net, V);

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
			for (pTemp = net[j].pNext; pTemp != NULL; pTemp = pTemp->pNext)
			{
				int k = pTemp->vertex;
				net[k].count--;
				if (!net[k].count)
					stack.Push(k);
			}
		}
	}
}