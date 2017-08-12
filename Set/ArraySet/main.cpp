#include <iostream>
#include "Set.h"
using namespace std;

int main(void)
{
	bool check;
	Set set;

	check = set.MakeSet();
	if (check == false)
		return 0;

	set.ShowAll();

	for (int i = 0; i < set.GetVertexNumber(); i++)
	{
		
		int elem, asso;
		cin >> elem;
		cin >> asso;
		if (elem == -1) break;
		set.FindSet(elem, asso, 1);
	}

	set.ShowAll();

	return 0;
}


