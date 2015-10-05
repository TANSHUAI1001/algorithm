//
#include <iostream>
using namespace std;
#include "Array.h"
#include "Container.h"
void testArray()
{
	//int array
	Array<int> IntArray(5);
	int i;
	for (i = 0;i < 5;i++)
	{
		IntArray.Enter(i,i);
	}
	cout<<"Integer Array:\n";
	for (i = 0;i < 5;i++)
	{
		cout<<IntArray.Entry(i)<<"\t";
	}
	cout<<endl;
	//double
	Array<double> DouArray(5);
	//int i;
	for (i = 0;i < 5;i++)
	{
		DouArray.Enter(i,i*1.23);
	}
	cout<<"Double Array:\n";
	for (i = 0;i < 5;i++)
	{
		cout<<DouArray.Entry(i)<<"\t";
	}
	cout<<endl;
}
void testContainer()
{

}
int main()
{
	testContainer();
	system("pause");

}