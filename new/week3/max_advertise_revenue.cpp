#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void insertion_sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int flag=0;
		for(int j=0;j<n-i-1;j++){
			if(arr[j+1]<arr[j]){
				arr[j+1]=arr[j+1]^arr[j];
				arr[j]=arr[j+1]^arr[j];
				arr[j+1]=arr[j+1]^arr[j];
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}

int main(){
	int n;
	cin>>n;

	int first[n],second[n];
	for(int i=0;i<n;i++){
		cin>>first[i];
	}
	for(int i=0;i<n;i++){
		cin>>second[i];
	}

	insertion_sort(first,n);
	insertion_sort(second,n);

	long long total=0;
	for(int i=0;i<n;i++){
		total += (long long)((long long)first[i])*second[i];
	}
	cout<<total<<endl;
}