#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>

using namespace std;

int min(int a,int b,int c){
int num = (a<b)?a:b;
if(num<c)
	return num;
return c;
}

int get_number(int arr[],long total,int count,int path[]){
	if(total==1)
		return 0;
	int min = INT_MAX,some;
	if(total%3==0 &&  total/3>0){
		if(arr[total/3]==0)
			arr[total/3] = get_number(arr,total/3,count+1,path);
		if(arr[total/3]<min){
			min=arr[total/3];
			some=total/3;
		}

	}
	if(total%2==0 &&  total/2>0){
		if(arr[total/2]==0)
			arr[total/2] = get_number(arr,total/2,count+1,path);
		if(arr[total/2]<min){
			min=arr[total/2];
			some=total/2;
		}

	}if(total-1>0){
		if(arr[total-1]==0)
			arr[total-1] = get_number(arr,total-1,count+1,path);
		if(arr[total-1]<min){
			min=arr[total-1];
			some=total-1;
		}
	}
	return min+1;
}




int main(){
	long n;
	cin>>n;
	int count[n+1]={0};
	int arr[100];
	int num = get_number(count,n,0,arr);
	cout<<num<<endl;

	for(int i=0;i<path.size();i++){
		cout<<path[i]<<" ";
	}
	return 0;

}