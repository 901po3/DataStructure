#include<iostream>
using namespace std;

//정렬이 되어있다는 전제하에 사용 가능
//사용하기전에 정렬을 하고 사용하자

int ShellSort(int a[], int n)
{
	int i, j, k;
	int step, temp;
	for(step=1; step<n; step = 3*step+1);
	for(step/=3; step > 0; step/=3)
	{
		for(i = 0; i < step; i++)
		{
			for(j = step + i; j < n; j += step)
			{
				k = j;
				temp = a[j];
				while( k > step-1 && a[k] < a[k-step])
				{
					a[k] = a[k-step];
					k -= step;
				}
				a[k] = temp;
			}
		}
	}
}


int BinarySearch(int key, int a[], int n)
{
	int mid;
	int left		= 0;
	int right	= n-1;
	while(right >= left)
	{
		mid = (right + left) / 2;
		if(key == a[mid]) return mid;
		if(key < a[mid]) right = mid-1;
		if(key > a[mid]) left = mid+1;
	}
	return -1;
}

int BinaryInsert(int key, int a[], int *np)
{
	int p = 0;
	int i;
	while(key > a[p] && p < *np) p++;
	for(i = *np; i > p; i--) a[i] = a[i-1];
	a[p] = key;
	(*np)++;
	return p;
}

int BinaryDelete(int key, int a[], int *np)
{
	int p;
	int i;
	if( *np > 0)
	{
		if(( p = BinarySearch(key, a, *np)) < 0) return -1;
		for(i = p+1; i < *np; i++) a[i-1] = a[i];
		(*np)--;
		return p;
	}
	return -1;
}