#pragma once

#define UNION		1
#define ONLY_UNION	0
#define name2int(c) ((int)(c - 'A'))
#define int2name(i) ((char)(i + 'A'))

enum { NUMBER, VERTEX, PARENT };

class Set
{
private:
	int **a;
	int v;
public:
	Set();
	~Set();

	int GetVertexNumber() { return v; }

	bool MakeSet();
	bool FindSet(int elem, int asso, bool flag);
	void ShowAll();
};
