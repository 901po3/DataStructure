#include<iostream>
using namespace std;

void SelectSort(int a[], int n)
{
	int min, minIndex;
	for(int i=0; i<n-1; i++)
	{
		minIndex = i;
		min = a[i];
		for(int j=i; j<n; j++)
		{
			if(min > a[j])
			{
				min = a[j];
				minIndex = j;
			}
		}
		a[minIndex] = a[i];
		a[i] = min;
	}
}