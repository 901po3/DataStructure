#include<iostream>
#include<cstdlib>
#include<time.h>

//merge sort is fast log(n) but It take 2 times of memory
using namespace std;

#define MAX			100
#define TRUE		true;
#define FALSE		false;

void MakeRandomNumber();
void DisplayBuffer();
int IsNumberExit(int, int);
void MergeSort(int [], int , int);

int buf[MAX];
int temp[MAX];

void MakeRandomNumber()
{
	int i, num;
	i = 1;
	srand((unsigned) time(NULL));
	buf[0] = 100;

	while(i < MAX)
	{
		num = rand() % MAX;

		if(!IsNumberExit(num, i))
		{
			buf[i] = num;
			i++;
		}
	}
}

void DisplayBuffer()
{
	for(int i=0; i<MAX; i++)
	{
		if((i % 10) == 0)
			cout<<endl;

		cout<<buf[i]<<"	";
	}
	cout<<endl;
}

int IsNumberExit(int number, int index)
{
	for(int i=0; i<index; i++)
	{
		if(buf[i] == number)
			return TRUE;
	}
	return FALSE;
}

void MergeSort(int data[], int left, int right)
{
	int i, j, k, middle;
	
	if(right > left)
	{
		middle = (left + right) / 2;

		MergeSort(data, left, middle);
		MergeSort(data, middle + 1, right);

		for(i = middle + 1; i > left; i--)
			temp[i - 1] = data[i - 1];

		for(j = middle; j < right; j++)
			temp[right + middle - j] = data[j + 1];

		for(k = left; k <= right; k++)
			data[k] = (temp[i] < temp[j]) ? temp[i++]: temp[j--];
	}
}

void main()
{
	cout<<"정렬할 데이터 초기화\n";

	MakeRandomNumber();
	DisplayBuffer();

	cout<<"정렬 후 데이터\n";

	MergeSort(buf, 0, MAX-1);
	DisplayBuffer();
	cout<<endl;

}