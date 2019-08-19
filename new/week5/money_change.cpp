#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int min(int a,int b,int c){
int num = (a<b)?a:b;
if(num<c)
	return num;
return c;
}

int get_number(int arr[],int money){
	if(money<0)
		return INT_MAX;
	else if(money<=2)
		return money;
	if(money-1>0 && arr[money-1]==0)
		arr[money-1]=get_number(arr,money-1);
	if(money-3>0 && arr[money-3]==0)
		arr[money-3]=get_number(arr,money-3);
	if(money-4>0 && arr[money-4]==0)
		arr[money-4]=get_number(arr,money-4);
	return min(arr[money-1],arr[money-3],arr[money-4]) + 1;
}



int main(){
	int n;
	cin>>n;
	int count[n+1]={0};
	int num = get_number(count,n);
	cout<<num<<endl;
	return 0;

}