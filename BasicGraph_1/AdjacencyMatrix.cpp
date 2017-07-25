#include<iostream>
using namespace std;

#define MAX_VERTEX		100

int G_Graph[MAX_VERTEX][MAX_VERTEX];

void InputAdjacencyMatrix(int graph[][MAX_VERTEX], int *pVertex, int *pEdge)
{
	int vertex[2];
	int i, j, k;

	cout << endl << "Input number of Vertex and Edge" << endl;
	cin >> *pVertex >> *pEdge;

	for (i = 0; i < *pVertex; i++)
		for (j = 0; j < *pEdge; j++) 
			graph[i][j] = 0;

	for (i = 0; i < *pVertex; i++) 
		graph[i][i] = 1;

	for (k = 0; k < *pEdge; k++)
	{
		cout << " Input two Vertex consist of Edge = ";
		for (int l = 0; l < 2; l++)
			cin>> vertex[l];
		i = vertex[0];
		j = vertex[1];
		graph[i][j] = 1;
		graph[j][i] = 1;
	}
}
