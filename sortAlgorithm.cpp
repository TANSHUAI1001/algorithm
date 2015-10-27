#include<iostream>
#include <time.h>
using namespace std;

void Swap(int * elem1,int * elem2)
{
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}
void NewSwap(int data[],int i,int j)
{
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
template<class T>
int getArrayLen(T& array)
{
	return sizeof(array)/sizeof(T);
	//return sizeof(array)/sizeof(array[0]);
}
//quick sort
int A[8] = {89,45,68,90,29,34,17,20};
int RandomInRange(int start, int end)  
{  
	srand(time(NULL));  
	return start + rand()%(end-start+1);  
}
int Partition(int data[],int l,int r)
{
	int index = RandomInRange(l,r);
	Swap(&data[index],&data[r]);
	int small = l - 1;
	for (index = l;index < r;++index)
	{
		if (data[index] < data[r])
		{
			++small;
			if(small != index)
				Swap(&data[index],&data[small]);
		}
	}
	//++small;
	//Swap(&data[small],&data[r]);
	Swap(&data[++small],&data[r]);
	return small;
}
void QuickSort(int data[],int l,int r)
{
	if(l==r)
		return;
	int index = Partition(data,l,r);
	if(index > l)
		QuickSort(data,l,index - 1);
	if(index < r)
		QuickSort(data,index + 1,r);
}

//bubble sort
//蛮力法F
int B[8] = {89,45,68,90,29,34,17,20};
//worst and average is n*n
void BubbleSort(int data[])
{
	int i,j,n = 8;
	for (i = 0;i < n - 1; i++)
	{
		for (j = 0;j < n-1-i; j++)
		{
			if(data[j+1] < data[j]) Swap(&data[j],&data[j+1]);
		}
	}
}
//merge sort
int C[8] = {89,45,68,90,29,34,17,20};
void MergeSort(int source[],int des[],int left,int right)
{
	if(left == right) return;
	int mid = (left + right)/2;
	MergeSort(source,des,left,mid);
	MergeSort(source,des,mid+1,right);
	for (int i = left;i <= right; i++)
	{
		des[i] = source[i];
	}
	
	int i1 = left;
	int i2 = right;
	for (int curr = left; curr <= right; curr++)
	{
		if(i1 == mid+1)
			source[curr] = des[i2++];
		else if(i2 > right)
			source[curr] = des[i1++];
		else if(des[i1] > des[i2])
			source[curr] = des[i1++];
		else source[curr] = des[i2++];
	}
}
//topological sort
int D[8] = {89,45,68,90,29,34,17,20};
void TopologicalSort()
{

}
//selection sort
int E[8] = {89,45,68,90,29,34,17,20};
void SelectionSort(int data[])
{
	//int len = getArrayLen(data);
	//cout<<len<<endl;
	int len = 8;
	int i,j;
	int currentMinIndex;
	int currentMin;
	for (i = 0; i < len; i++)
	{
		currentMinIndex = i;
		currentMin = data[currentMinIndex];
		for (j = i; j < len; j++)
		{
			if (data[j] < currentMin)
			{
				currentMin = data[j];
				currentMinIndex = j;
			}
		}
		if (currentMinIndex != i)
			Swap(&data[i],&data[currentMinIndex]);
	}
}
//insertion sort
int F[8] = {89,45,68,90,29,34,17,20};
void InsertionSort(int data[])
{
	//cout<<n<<endl;
	int n = 8;
	int i,j;
	for (i = 1; i < n;i++)
	{
		int current = data[i];
		for (j = i - 1; (j >= 0) && (data[j] > current); j--) // current 不能用 data[i], for 循环可能执行多次，data[i] 已经改变
		{
			data[j+1] = data[j];
		}
		data[j+1] = current;
	}
}
//shell sort
// 时间复杂度在O(n*log2 n)和O(n*n)之间
int G[8] = {89,45,68,90,29,34,17,20};
void InsertionSort2(int data[],int n,int incr)
{
	int i,j;
	for (i = incr; i < n; i += incr)
	{
		int temp = data[i];
		for (j = i - incr; (j >= incr - 1)&&(data[j] > temp); j -= incr)
		{
			data[j+incr] = data[j];
			//Swap(&data[j],&data[j+1]);
			//NewSwap(data,j,j+incr);
		}
		data[j+incr] = temp;
	}
}
void ShellSort(int data[],int n)
{
	int i,j;
	for (i = n/2; i > 2; i/=2)
	{
		for (j = 0; j < i; j++)
		{
			InsertionSort2(&data[j],n-j,i);
		}
	}
	InsertionSort2(data,n,1);
}

//以下为别人的代码，不确认是否精准
/* merge函数： 
* 将source[start..mid]和source[mid+1..end]中的元素归并有序序列des[start..end] 
* 
* */  
void merge(int *source, int *des, int start, int mid, int end)  
{
    int i = start;  
    int j = mid + 1;  
    int k = start;    
    while(i <= mid && j <= end) {  
	// if(source[i] <= source[j])  
    //     des[k++] = source[i++];  
    // else  
    //     des[k++] = source[j++];  
     des[k++] = source[i] <= source[j] ? source[i++] : source[j++];  
	}    
	while(i <= mid)
		des[k++] = source[i++];  
	while(j <= end)  
		des[k++] = source[j++];  
}  
  
/* mpass函数： 
 * 将参加排序的序列分成若干个长度为t的，且各自按值有序的子序列， 
 * 然后多次调用归并子算法merge将所有两两相邻成对的子序列合并成 
 * 若干个长度为2t的，且各自按值有序的子序列。 
 *  
 * 若最后一趟排序时，剩下的元素不足2t个元素： 
 * 1. 
 *  若剩余元素个数大于t，则再调用一次merge算法将剩余的两个不等长子序列合并为一个子序列 
 * 2. 
 *  若剩余元素个数小于等于t，则直接将所有剩余元素依次复制到前一个子序列的后面 
 * */  
void mpass(int *source, int *des, int len, int t)  
{
	int i = 0;  
	if(len - i >= 2*t) {
		merge(source, des, i, i + t - 1, i + 2 * t - 1);  
	    i += 2 * t;  
	}  
	 
	if(len - i > t)
		merge(source, des, i, i + t - 1, len - 1);  
	else {
		for(; i < len; ++i)
			des[i] = source[i];
	}
}  
   
/* mergeSort排序： 
 * |flag|，若flag = -1，则表示输入参数错误； 
 * 若flag = 1， 则表示排好序的元素存放于data序列中 
 * 若flag = 0，则表示排好序的元素存放于des序列中 
 * 1.  
 *  总共会进行log2n趟排序，每趟排序调用mpass函数，mpass的时间复杂度为O(n)，二路归并排序的时间复杂度为O(nlog2n) 
 * 2. 
 *  排序过程中需要同原始序列同等大小的辅助空间，空间复杂度为O(n) 
 * 3. 
 *  二路归并排序是稳定性排序 
 * 4. 
 *  二路归并排序的时间复杂度与序列的初始状态无关 
 */  
int mergeSort(int *data, int *des, int len)  
{
	int flag = -1;  
    if(data == NULL || len < 1)
		return flag;  
	 
	int t = 1;  
	flag = 1;  
	while(t < len) {  
		mpass(data, des, len, t);  
		flag = 0;  

		t *= 2;  
		if(t < len) {  
			mpass(des, data, len, t);  
			t *= 2;  
			flag = 1;  
		}  

		return flag;  
	}  
}


int main()
{
	int i;
	
	QuickSort(A,0,7);
	for(i = 0;i < sizeof(A)/sizeof(int);i++)
		cout<<A[i]<<"\t";
	cout<<endl;

	BubbleSort(B);
	for(i = 0;i < sizeof(B)/sizeof(int);i++)
		cout<<B[i]<<"\t";
	cout<<endl;

	SelectionSort(E);
	for(i = 0;i < sizeof(E)/sizeof(int);i++)
		cout<<E[i]<<"\t";
	cout<<endl;

	InsertionSort2(F,8,1);
	for(i = 0;i < sizeof(F)/sizeof(int);i++)
		cout<<F[i]<<"\t";
	cout<<endl;

	ShellSort(G,8);
	for(i = 0;i < sizeof(G)/sizeof(int);i++)
		cout<<G[i]<<"\t";
	cout<<endl;

	int temp[8];
	merge(C,temp,0,4,7);
	for(i = 0;i < sizeof(temp)/sizeof(int);i++)
		cout<<temp[i]<<"\t";
	cout<<endl;

	system("pause");
}