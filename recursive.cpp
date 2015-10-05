#include <iostream>
int AddFrom1toN(int n)
{
	return n<=0?0:n+AddFrom1toN(n-1);
}
int main(){
	int x = AddFrom1toN(10);
	printf("%d",x);
	system("pause");
}