#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
#include "Container.h"
// containers --> vector,list
struct Order
{
	int number;
	double num;
};

void printVector(vector<int> & Vector)
{
	vector<int>::iterator p;
	p = Vector.begin();
	while (p != Vector.end())
	{
		cout<<*p<<"\t";
		p++;
	}
	cout<<endl;
}
void printList(list<int> & List)
{
	list<int>::iterator p;
	p = List.begin();
	while (p != List.end())
	{
		cout<<*p<<"\t";
		p++;
	}
	cout<<endl;
}
//ASC //DESC
// vector
bool searchMatrix(vector<vector<int>>& matrix, int target){
	unsigned int length = matrix.size();
	if(length == 0)
		return false;
	int j = matrix[0].size()-1;
	int i = 0;
	while (true)
	{
		cout<<"current position is "<<i<<"\t"<<j<<endl;
		if (matrix[i][j] == target)
			return true;
		else if(matrix[i][j] > target)
		{
			//i++;
			if(j == 0)
				return false;
			else
				j--;
		} 
		else if(matrix[i][j] < target)
		{
			if(i == length-1)
				return false;
			else
				i++;
		}
		else
		{
			return false;
		}
	}
	
}
void createMatrix(){
	int m,n,i,j;
	m = 6;
	n = 5;
	//vector<vector<int>> matrix(m,vector<int>(n));
	vector<vector<int>> matrix(m);
	vector<int> temp(n);
	for(i = 0;i < m;i++){
		temp.clear();
		for(j = 0;j < n;j++){
			temp.push_back(i+j);
			//temp.push_back((i+j) * rand()%100);
		}
		//sort(temp.begin(), temp.end());  //默认情况为升序
		//matrix.push_back(temp);
		//printVector(temp);
		matrix[i] = temp;
	}
	printf("%s\n",typeid(matrix.size()).name());
	cout<<typeid(matrix.size()).name()<<endl;
	for (unsigned int i = 0; i < matrix.size();i++)
	{
		for (size_t j = 0;j < matrix[i].size();j++)
		{
			//cout<<matrix[i]<<endl;
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<searchMatrix(matrix,4)<<endl;
	cout<<searchMatrix(matrix,100)<<endl;
	cout<<searchMatrix(matrix,-1)<<endl;
}
void checkVectorCapacity()
{
	vector<int> v;
	/*
	v.push_back(1);
	cout << v.capacity() << endl;  // 1
	v.push_back(2);
	cout << v.capacity() << endl;  // 2
	v.push_back(3);
	cout << v.capacity() << endl; // 4
	v.push_back(4);
	cout << v.capacity() << endl;
	v.push_back(5);
	cout << v.capacity() << endl;
	v.push_back(6);
	cout << v.capacity() << endl;
	*/
	for (int i = 0; i < 20;i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl;
	}
}
//list
void createList(list<int> & orderList,int len)
{
	int i,k;
	for(i = 0; i < len; i++)
	{
		k = rand()%100;
		orderList.push_back(k);
	}
	//orderList.sort();//没有sort合并时候回报错。
}

void testList()
{
	list<int> L1,L2;
	createList(L1,10);
	cout<<"L1:\n";
	printList(L1);
	L1.sort();
	cout<<"sorted L1:\n";
	printList(L1);
	cout<<"L2:\n";
	createList(L2,5);
	L2.sort();
	printList(L2);
	cout<<"push same element:\n";
	L1.push_back(1001);
	printList(L1);
	L2.push_back(1001);
	printList(L2);
	cout<<"merge L1 and L2:\n";
	L1.merge(L2);
	printList(L1);
	//cout<<L1.capacity()<<endl;
	cout<<"reverse:\n";
	L1.reverse();
	printList(L1);
	cout<<"unique L1:\n";
	L1.unique();
	printList(L1);

	PrintContainer<list<int>> test(L1);

}
int main(){
	//int n = 5;
	//cout<<vector<int>(n);
	//createMatrix();
	//checkVectorCapacity();
	testList();
	system("pause");
}