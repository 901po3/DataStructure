#include<iostream>
using namespace std;

int arr[256];
int count;

void InitStack()
{
	count=-1;
}

void Push(int data)
{
	arr[++count] = data;
}

bool IsStackEmpty()
{
	if(count == -1)
		return true;
	else 
		return false;
}

int Pop()
{
	return arr[count--];
}

void QuickSort(int a[], int n)
{
	int temp, pivot;
	int i,j;
	int first, last;
	InitStack();
	first = 0;
	last = n-1;
	Push(last);
	Push(first);

	while(!IsStackEmpty())
	{
		first = Pop();
		last = Pop();
		
		if(last-first+1 > 1)
		{
			pivot = a[last];
			i = first-1;
			j = last;
			while(1)
			{
				while(a[++i] < pivot);
				while(a[--j] > pivot);
				if(i >= j) break;
				temp = a[i];
				a[i] = a[j];
				a[i] = temp;
			}
			temp = a[last];
			a[last] = a[i];
			a[i] = temp;

			Push(last);
			Push(i+1);
			Push(i-1);
			Push(first);
		}
	}
}

void main()
{
	int arr[5] ={5,4,3,2,1};
	QuickSort(arr,5);
	for(int i=0; i<5; i++)
		cout<<arr[i]<<endl;
}