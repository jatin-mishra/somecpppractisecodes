#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;


int find_pivot(int array[],int start,int last){

	int member = array[last];
	int j=start-1;
	int temp;
	for(int i=start;i<last;i++){
		if(array[i]<=member){
			j++;
			// cout<<"before swapping "<<array[i]<<" "<<array[j]<<endl;
			temp = array[i];
			array[i] =array[j];
			array[j] = temp;
			// cout<<"after swapping "<<array[i]<<" "<<array[j]<<endl;
		}	
	}
	j++;
	array[last]=array[j];
	array[j]=member;
	return j;

}





void quick_sort(int array[],int start,int last){
	if(last>start){
		int pivot = find_pivot(array,start,last);
		// cout<<"pivot is : "<<pivot<<" element "<<array[pivot]<<endl;
		quick_sort(array,start,pivot-1);
		quick_sort(array,pivot+1,last);
	}
}






int main(){

	// int p=0;
	// while(p<=10){
	// 	cout<<"--------------------------------"<<endl;
	// int n = 2 +  rand() % 100;
	int n;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++){
		// array[i]=rand()%10;
		// cout<<array[i]<<" ";
		cin>>array[i];
	}
	// cout<<endl;
	quick_sort(array,0,n-1);
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
// 	p++;
// }
return 0;
}