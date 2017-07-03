#include<iostream>
using namespace std;

//Quick 정렬의 기본 순서
//배열의 마지막 인자를 pivot으로 잡고
//첫번째부터 pivot보다 큰 수를 찾고				i++;
//pivot바로 전 인자부터 pivot보다 작은 수를 찾고	j--;
//찾은 두 인자를 교환
//그리고 두 인자의 인덱스값이 교차할때 (i>= j)
//pivot의 위치를 배열[i]랑 자리교대
//그리고 재귀함수호출

//void QuickSort(int a[], int n)
//{
//	int v, t;
//	int i, j;
//	if(n>1)
//	{
//		v = a[n-1];
//		i = -1;
//		j = n-1;
//		while(1)
//		{
//			while(a[++i] < v);
//			while(a[--j] > v);
//			if(i >= j)
//				break;
//			t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//
//		t = a[i];
//		a[i] = a[n-1];
//		a[n-1] = t;
//		QuickSort(a,i);
//		QuickSort(a+i+1, n-1-i);
//	}
//}

void QuickSort(int a[], int n)
{
	int pivot, temp;
	int i,j;

	if(n>1)
	{
		pivot = a[n-1];
		i = -1;
		j = n-1;

		while(1)
		{
			while(a[++i] < pivot);
			while(a[--j] > pivot);
			if(i >= j) break;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		temp = pivot;
		a[n-1] = a[i];
		a[i] = pivot;

		QuickSort(a, i);
		QuickSort(a+i+1, n-i-1);

	}
}
