#include <iostream>
#include "common.h"
using namespace std;

void InputAdjMatrix(int g[][MAX_VERTEX], int *V, int *E)
{	//방향 그래프를 위한 인접 행렬 입력 함수
	char vertex[3];
	int i, j, k;
	printf("\nInput number of Vertex & Edge\n");
	cin >> *V >> *E;

	for (i = 0; i < *V; i++)
		for (j = 0; j < *V; j++) g[i][j] = 0;
	for (i = 0; i < *V; i++)
		g[i][i] = 0;
	for (k = 0; k < *E; k++)
	{
		printf("\nInput two Vertex consist of Edge -> ");
		cin >> vertex;
		i = name2int(vertex[0]);
		j = name2int(vertex[1]);
		g[i][j] = 1;
	}
}
