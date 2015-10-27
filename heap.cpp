#include <iostream>
using namespace std;
int LeftChild(int i)
{
	return 2*i+1;
}
int RightChild(int i)
{
	return 2*(i+1);
}
void AdjustHeap(int A[],int len,int i)
{
	int left = LeftChild(i);
	int right = RightChild(i);
	int largest = i;
	int temp;
	while (left < len || right < len)
	{
		if (left < len && A[largest] < A[left])
		{
			largest = left;
		}
		if (right < len && A[largest] < A[right])
		{
			largest = right;
		}
		if (i != largest)
		{
			temp = A[largest];
			A[largest] = A[i];
			A[i] = temp;
			
			i = largest;
			left = LeftChild(i);
			right = RightChild(i);
			cout<<i<<endl;
		}
		else break;
	}
}

void BuildHeap(int A[],int len)
{
	int i,j;
	int begin = len/2 - 1; //最后一个非叶子结点
	for (i = begin; i >= 0; i--)
	{
		cout<<"out i = "<<i<<endl;
		AdjustHeap(A,len,i);
		for (j = 0; j < 10; j++)
		{
			cout<<A[j]<<" ";
		}
		cout<<endl;
	}
}

void HeapSort(int A[],int len)
{
	int hLen = len;
	int temp;
	BuildHeap(A,hLen);
	for (int i = 0; i < 10; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	while (hLen > 1)
	{
		temp = A[hLen-1];
		A[hLen-1] = A[0];
		A[0] = temp;
		hLen--;
		AdjustHeap(A,hLen,0);
	}
}

void main()
{
	int A[10] = {73,6,57,88,60,42,83,72,48,85};
	//BuildHeap(A,10);
	HeapSort(A,10);
	for (int i = 0; i < 10; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	//if(1000 > A[10])
	//	cout<<A[10]<<"what !"<<endl;
	system("pause");
};