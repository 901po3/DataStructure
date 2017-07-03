#include<iostream>
using namespace std;

//Quick ������ �⺻ ����
//�迭�� ������ ���ڸ� pivot���� ���
//ù��°���� pivot���� ū ���� ã��				i++;
//pivot�ٷ� �� ���ں��� pivot���� ���� ���� ã��	j--;
//ã�� �� ���ڸ� ��ȯ
//�׸��� �� ������ �ε������� �����Ҷ� (i>= j)
//pivot�� ��ġ�� �迭[i]�� �ڸ�����
//�׸��� ����Լ�ȣ��

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
