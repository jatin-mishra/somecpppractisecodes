#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdbool>

using namespace std;

bool is_num_min_compare(int a,int num){
	int len1=0,len2=0,first=0,second=0;
	int reverse1=0,reverse2=0;
	int a_end = a%10,num_end = num%10;
	while(num>0){
		reverse1 =  10*reverse1 + (num%10);
		num = num/10;
		len1++;
	}
	int num_start = reverse1%10;
	while(a>0){
		reverse2 =  10*reverse2 + (a%10);
		a = a/10;
		len2++;
	}

	int a_start = reverse2 % 10;
	if(reverse1 ==0 || reverse2==0)
		return num<a;

	while(reverse1>0 && reverse2>0){
		 first =reverse1%10;
		 second = reverse2%10;
		 reverse1/=10;
		 reverse2/=10;
		 if(first<second){
		 	return true;
		 }else if(first>second){
		 	return false;
		 }
	}
	int its_second,its_first;
	its_first = 10*a_end + num_start;
	its_second = 10*num_end + a_start;
	// cout<<its_first<<" "<<its_second<<endl;

	if(len1 == len2)
		return num_end<a_end;
	else if(its_first!=its_second)
		return its_first>its_second;
	else
		return len1>len2;
	
}


void insertion_sort(int numbers[],int size){
	int j,num;
	for(int i=1;i<size;i++){
		j = i-1;
		num = numbers[i];
		while(j>=0 && is_num_min_compare(numbers[j],num)){
			numbers[j+1]=numbers[j];
			j--;
		}
		numbers[j+1]=num;
	}
}




int main(){
	int n;
	// cin>>n;
	int p=0;
	while(p<10){
	n = 2 + rand() % 10;
	int numbers[n];
	for(int i=0;i<n;i++){
		// cin>>numbers[i];
		numbers[i] = rand() % 20;
		cout<<numbers[i]<<" ";
	}
	cout<<"\n\n\n"<<endl;


	insertion_sort(numbers,n);
	for(int i=n-1;i>=0;i--){
		cout<<numbers[i]<<" ";
	}
	cout<<"\n\n\n"<<endl<<"---------------------"<<endl;
	p++;
}
	return 0;
}