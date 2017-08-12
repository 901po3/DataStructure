#include <iostream>
#include"Set.h"
using namespace std;

Set::Set()
{
	cin >> v;
	a = new int*[3];
	for (int i = 0; i < 3; i++)
		a[i] = new int[v];

	int i;
	for (i = 0; i < v; i++)
		a[NUMBER][i] = i;
	for (i = 0; i < v; i++)
		a[VERTEX][i] = int2name(i);
	for (i = 0; i < v; i++)
		a[PARENT][i] = -1;
}

Set::~Set()
{
	for (int i = 0; i < 3;i++)
		delete a[i];
	delete a;
}

bool Set::MakeSet()
{
	int i, j, p;
	bool check = false;

	for (i = 0; i < v; i++)
	{
		cin >> p;
		for (j = 0;j < v; j++)	//존재하는 첨자를 첬는지 체크
			if (p == a[NUMBER][j] || p == -1)
				check = true;
		if (check == false) return false;

		a[PARENT][i] = p;

		check = false;
	}

	return true;
}

bool Set::FindSet(int elem, int asso, bool flag)
{
	int i = elem, j = asso;

	while (a[PARENT][i] >= 0)
		i = a[PARENT][i];
	while (a[PARENT][j] >= 0)
		j = a[PARENT][j];

	if (flag == UNION && i != j)
	{
		a[PARENT][elem] = asso;
	}
	return i == j ? true : false;
}

void Set::ShowAll()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (j == VERTEX)
				cout << a[i][j] << "	";
			else
				cout << a[i][j] << "	";
		}
		cout << endl;
	}
}