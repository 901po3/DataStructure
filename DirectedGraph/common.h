#pragma once

#define name2int(c) (c - 'A')
#define int2name(i) (i + 'A')

#define MAX_VERTEX		100

int check[MAX_VERTEX];

struct Node
{
	int vertex;
	Node *pNext;
};

////Topological Order
struct Head
{
	int count;
	Node *pNext;
};

Head network[MAX_VERTEX];