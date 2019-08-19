#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdbool>
#include <cmath>

using namespace std;

bool is_num_min_compare(int a,int num){

	if(num==0 || a==0)
		return num<a;
	int len1 = (log(num)/log(10))+1;
	int len2 = (log(a)/log(10)) + 1;
	int first[len1+len2];
	int second[len2+len1];
	int reverse2=0,reverse1=0;
	while(num>0){
		reverse1 =  10*reverse1 + (num%10);
		num = num/10;
	}
	while(a>0){
		reverse2 =  10*reverse2 + (a%10);
		a = a/10;
	}
	int len_1 = (log(reverse1)/log(10)) + 1;
	int len_2 = (log(reverse2)/log(10)) + 1;

	for(int i=0;i<len1;i++){
		if(i<len_1){
			first[i]=reverse1%10;
			reverse1=reverse1/10;
		}
		if(i>=len_1){
			first[i]=0;
		}
	}

	for(int i=0;i<len2;i++){
		if(i<len_2){
			second[i]=reverse2%10;
			reverse2=reverse2/10;
		}
		if(i>=len_2){
			second[i]=0;
		}
	}

for(int i=len1;i<len1+len2;i++){
	first[i]=second[i-len1];
}for(int i=len2;i<len1+len2;i++){
	second[i]=first[i-len2];
}
for(int i=0;i<len1+len2;i++){
	if(first[i]<second[i])
		return true;
	else if(first[i]>second[i])
		return false;
}
return false;

}


void insertion_sort(int numbers[],int size){
	int j,num;
	for(int i=1;i<size;i++){
		j = i-1;
		num = numbers[i];
		while(j>=0 && is_num_min_compare(numbers[j],num)){
			// cout<<is_num_min_compare(numbers[j],num)<<endl;
			// cout<<numbers[j]<<" "<<numbers[j+1]<<endl;
			numbers[j+1]=numbers[j];
			// cout<<numbers[j]<<" "<<numbers[j+1]<<endl;
			j--;
		}
		numbers[j+1]=num;
			// cout<<numbers[j+1]<<" "<<numbers[j+2]<<endl;

	}
}




int main(){
	int n;
	cin>>n;
	// int p=0;
	// while(p<10){
	// n = 2 + rand() % 10;
	int numbers[n];
	for(int i=0;i<n;i++){
		cin>>numbers[i];
		// numbers[i] = rand() % 20;
		// cout<<numbers[i]<<" ";
	}
	// cout<<"\n\n\n"<<endl;


	insertion_sort(numbers,n);
	for(int i=n-1;i>=0;i--){
		cout<<numbers[i];
	}
	// cout<<endl;
	// for(int i=n-1;i>=0;i--){
	// 	cout<<(int)(log(numbers[i])/log(10))+1<<" ";
	// }
	// cout<<"\n\n\n"<<endl<<"---------------------"<<endl;
	// p++;
// }
	return 0;
}