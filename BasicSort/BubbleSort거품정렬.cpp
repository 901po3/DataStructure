#include<iostream>
using namespace std;

//int IsSorted(int a[], int n) //배열이 정령이 되 있는지 확인
//{
//	int i, s;
//	s = 1;
//	for(i=1; i<n; i++)
//		if(a[i-1] > a[i]) s = 0;
//	return s;
//}
//
//void BubbleSort1(int a[], int n)
//{
//	int i, j, t, s;
//	for(i=0; i<n-1; i++)
//	{
//		s = 1;
//		for(j=1; j<n-i; j++)
//		{
//			t = a[j-1];
//			a[j-1] = a[j];
//			a[j] = t;
//			s = 0;
//		}
//		if(s==1)
//			break;
//	}
//}

void BubbleSort(int a[], int n)
{
	int temp;
	for(int i=0; i<n-1; i++)
	{
		for(int j=1; j<n-i; j++)
		{
			if(a[j] < a[j-1])
			{
				temp  = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}