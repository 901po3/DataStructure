#include <iostream>
#include "common.h"
using namespace std;

void Floyd(int d[][MAX_VERTEX], int V)	//shortest way
{
	int x, y, i;

	for (y = 0; y < V; y++)
		for (x = 0; x < V; x++)
			for (i = 0; i < V; i++)
			{
				if (d[x][y] + d[y][i] < d[x][i])
					d[x][i] = d[x][y] + d[y][i];
			}
}