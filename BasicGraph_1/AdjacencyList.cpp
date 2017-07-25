#include<iostream>
using namespace std;

#define MAX_VERTEX		100

struct Node
{
	int vertex;
	Node *pNext;
};

Node *G_pGraph[MAX_VERTEX];

void InputAdjacencyList(Node *pGraph[], int *pVertex, int *pEdge)
{
	int vertex[2];
	int i, j;
	Node *pTemp;
	cout << endl << "Inpute number of Vertex and Edge " << endl;
	cin >> *pVertex >> *pEdge;
	
	for (i = 0; i < *pVertex; i++)
		pGraph[i] = NULL;

	for (j = 0; j < *pEdge; j++)
	{
		cout << endl << "Input two Vertex consist of Edge = ";
		for (int l = 0; l < 2; l++)
			cin >> vertex[l];
		i = vertex[0];
		pTemp = new Node;
		pTemp->vertex = vertex[1];
		pTemp->pNext = pGraph[i]; 
		pGraph[i] = pTemp;

		i = vertex[1];
		pTemp = new Node;
		pTemp->vertex = vertex[0];
		pTemp->pNext = pGraph[i];
		pGraph[i] = pTemp;
	}
}