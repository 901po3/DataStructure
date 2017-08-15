#include <iostream>
#include "common.h"
using namespace std;

void Warshall(int c[][MAX_VERTEX], int V)
{
	for (int y = 0; y < V; y++)
		for (int x = 0; x < V; x++)
			if (c[x][y])
				for (int i = 0; i < V; i++)
					if (c[y][i])
						c[x][i] = 1;
}