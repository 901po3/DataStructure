#include <iostream>
#include "ArrayStack.h"
#include "common.h"
using namespace std;

int order;

int StrongRecur(Node *g[], int i)
{
	int m, min;
	int k;
	int flag;
	Node *pTemp;
	ArrayStack stack;
	check[i] = min = ++order; //
	stack.Push(i);
	for (pTemp = g[i]; pTemp != NULL; pTemp = pTemp->pNext)
	{
		if (check[pTemp->vertex] == 0) //방문하지 않은 정점이면
			m = StrongRecur(g, pTemp->vertex); 
		//비나무 간선을 통해 올라갈 수있는 정점 얻음
		else
			m = check[pTemp->vertex];

		if (m < min) min = m;
	}
	if (min == check[i]) //자기 자신을 가리키게 되면 회로인지 검사
	{
		flag = 0;
		while ((k = stack.Pop()) != i)
		{//이 루프를 돌지 않으면 회로가 아님
			printf("%c ", int2name(k));
			check[k] = MAX_VERTEX + 1;

			flag = 1;
		}
		if (flag) printf("%c\n", int2name(k));
	}
	return min;
}

void Strong(Node *g[], int V)
{
	int i, k;
	for (i = 0; i < V; i++)
		check[i] = 0;
	for (i = 0; i < V; i++)
	{
		if (check[i] == 0)
			StrongRecur(g, i);
	}
}