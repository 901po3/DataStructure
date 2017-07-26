#include <iostream>
using namespace std;

#define MAX_VERTEX			100

int check[MAX_VERTEX];

void Visit(int i)
{
	cout << i << endl;
}

void DFSRecursive(int a[][MAX_VERTEX], int vertex, int i)
{
	int j;
	check[i] = 1;
	Visit(i);
	
	for (j = 0; j < vertex; j++)
	{
		if (a[i][j] != 0)
			if (check[j] == 0)
				DFSRecursive(a, vertex, j);
	}
}

void DFSAdjacencyMatrix(int a[][MAX_VERTEX], int vertex)
{
	int i;
	for (i = 0; i < vertex; i++) check[i] = 0;
	for (i = 0; i < vertex; i++)
		if (check[i] == 0) DFSRecursive(a, vertex, i);
}


