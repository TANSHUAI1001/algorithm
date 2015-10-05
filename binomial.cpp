#include <stdio.h>
#include<iostream>
#include <algorithm>
using namespace std;
#define COM_MIN(x,y) (x>y?y:x)
int Binomial(int n,int k);
int main(void)
{
int i1=4,i2=5;
int sum=i1+i2;
//cout<<COM_MIN(i1,i2)<<endl;
printf("%d\n",Binomial(i2,i1));
system("pause");
return 0;
}
int Binomial(int n,int k)
{
	int **C;
	C = new int *[n+1];
	for(int t=0;t<n+1;t++){
		C[t] = new int[k+1];
	}
	for(int a=0;a<n+1;a++){
		for (int b=0;b<k+1;b++)
		{
			C[a][b]=0;
		}
	}
	for(int i=0;i<n+1;i++){
		for (int j=0;j<COM_MIN(i,k)+1;j++)
		{
			if (j==0 || j==i)
			{
				C[i][j]=1;
			} 
			else
			{
				C[i][j]=C[i-1][j-1] + C[i-1][j];
			}
		}
	}
	
	for(int a=0;a<n+1;a++){
		for (int b=0;b<k+1;b++)
		{
			printf("%d\t",C[a][b]);
		}
		printf("\n");
	}
	int val = C[n][k];
	for(int t=0;t<k+1;t++){
		printf("deleting\n");
		delete [] C[t];
	}
	delete [] C;
	return val;
}