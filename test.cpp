#include<iostream>

int main(){
	int i = 0;
	int n = 10;
	int result = 0;
	while(i < n){
		result += i;
		i++;
	}
	printf("%d",result);
	return 0;
}