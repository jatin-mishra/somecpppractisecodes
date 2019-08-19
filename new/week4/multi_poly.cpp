#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void multiply_polynomial(int first[],int second[],int add_from,int start1,int start2,int size,int new_ar[],int new_size){
	if(size==1){
		new_ar[add_from]+=first[start1]*second[start2];
	}else{
		multiply_polynomial(first,second,add_from + size,start1,start2,size/2,new_ar,new_size);
		multiply_polynomial(first,second,add_from + (size/2),start1,start2+(size/2),size/2,new_ar,new_size);
		multiply_polynomial(first,second,add_from+(size/2),start1+(size/2),start2,size/2,new_ar,new_size);
		multiply_polynomial(first,second,add_from,start1+(size/2),start2+(size/2),size/2,new_ar,new_size);
	}
}

int main(){
	int n,start=0;
	cin>>n;

	int first[n];
	int second[n];
	if(n%2 != 0){
		start=1;
		n++;
		first[0]=0;
		second[0]=0;
	}

	for(int i=start;i<n;i++)
		cin>>first[i];
	for(int j=start;j<n;j++)
		cin>>second[j];

	int size = 2*n-1;
	int new_ar[size]={0};
	multiply_polynomial(first,second,0,0,0,n,new_ar,size);

	if(start==1)
		size=size-2;

	for(int i=size-1;i>=0;i--){
		cout<<new_ar[i]<<" ";
	}
	return 0;
}