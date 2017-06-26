#include<iostream>
using namespace std;

//void InsertionSort(int a[], int n)
//{
//	int i, j, t;
//	for(i=1; i<n; i++)
//	{
//		t = a[i];
//		j=i;
//		while(a[j-1] > t && j > 0)
//		{
//			a[j] = a[j-1];
//			j--;
//		}
//		a[j] = t;
//	}
//}
//


void InsertionSort(int a[] , int n)
{
	int i,j,t;
	for(i=1; i<n; i++)
	{
		t = a[i];
		for(j=i; a[j-1]>t && j>0; j--)
		{
			a[j] = a[j-1];
		}
		a[j] = t;
	}
}
//
//void InsertionSort2(int a[], int n)
//{
//	for(int i=1; i<n; i++)
//	{
//		int t = a[i];
//		for(int j=i; j>0; j++)
//		{
//			if(t <a[j-1])
//				a[j] = a[j-1];
//		}
//	}
//	a[j] = t;
//}