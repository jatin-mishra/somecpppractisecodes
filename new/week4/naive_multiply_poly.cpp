#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;

	int first[n];
	int second[n];

	for(int i=0;i<n;i++){
		cin>>first[i];
	}

	for(int i=0;i<n;i++){
		cin>>second[i];
	}

	int size = 2*n - 1;
	int total[size]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			total[i+j]=total[i+j] + first[i]*second[j];
		}
	}
	for(int k=0;k<size;k++){
		cout<<total[k]<<" ";
	}

	return 0;
}
