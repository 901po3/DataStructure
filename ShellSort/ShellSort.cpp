#include<iostream>
using namespace std;

//void ShellSort(int a[], int n) //normal shell sort
//{
//	int i,j;
//	int gap;
//	int saveValue;
//	int saveIndex;
//
//	for(gap = n/2; gap > 0; gap /= 2)
//	{
//		for(i = 0; i < gap; i++)
//		{
//			for(j = gap + i; j < n; j += gap)
//			{
//				saveValue = a[j];
//				saveIndex = j;
//				while(saveIndex > gap - 1 && saveValue < a[saveIndex-gap])
//				{
//					a[saveIndex] = a[saveIndex - gap];
//					saveIndex -= gap;
//				}
//				a[saveIndex] = saveValue;
//			}
//		}
//	}
//}


void ShellSort(int a[], int n)
{
	int i,j;
	int gap;
	int saveValue;
	int saveIndex;

	for(gap = 1; gap < n; gap = 3 * gap + 1); //average 20% faster by adding this loop;
	for(gap /= 3; gap > 0; gap /= 3)
	{
		for(i = 0; i < gap; i++)
		{
			for(j = gap + i; j < n; j += gap)
			{
				saveValue = a[j];
				saveIndex = j;
				while(saveIndex > gap - 1 && saveValue < a[saveIndex - gap])
				{
					a[saveIndex] = a[saveIndex - gap];
					saveIndex -= gap;
				}
				a[saveIndex] = saveValue;
			}
		}
	}
}

