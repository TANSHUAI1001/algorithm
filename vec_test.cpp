#include <iostream>
#include <vector>
using namespace std;

int main(){
	unsigned int i;
	vector<int> vec(10,0);
	for (i=0;i<10;i++){
		cout<<vec[i]<<endl;
		vec[i] = i;
		cout<<vec[i]<<endl;
	}
	vec.push_back(100);
	//cout<<vec<<endl;
	system("pause");
}