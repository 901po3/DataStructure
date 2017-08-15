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
		if (check[pTemp->vertex] == 0) //�湮���� ���� �����̸�
			m = StrongRecur(g, pTemp->vertex); 
		//�񳪹� ������ ���� �ö� ���ִ� ���� ����
		else
			m = check[pTemp->vertex];

		if (m < min) min = m;
	}
	if (min == check[i]) //�ڱ� �ڽ��� ����Ű�� �Ǹ� ȸ������ �˻�
	{
		flag = 0;
		while ((k = stack.Pop()) != i)
		{//�� ������ ���� ������ ȸ�ΰ� �ƴ�
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