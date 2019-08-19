#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void insertion_sort(long values[],long weight[],int size ){
	for(int i=size-2;i>=0;i--){
		int j=i+1;
		long vl = values[i];
		long wt = weight[i];
		long double num = (long double)((long double)values[i]/weight[i]);
		while(j<=size-1 && (long double)((long double)values[j]/weight[j])>num ){
			values[j-1] = values[j];
			weight[j-1] = weight[j];
			j++;
		}
		values[j-1] = vl;
		weight[j-1] = wt;
	}
}             


int main(){
	int n;
	long capacity;
	// n = rand()%1000;
	cin>>n>>capacity;
	long weight[n];
	long values[n];
	for(int i=0;i<n;i++){
		// values[i]
		cin>>values[i]>>weight[i];
	}

	insertion_sort(values,weight,n);

long double total=0.0;
int j = 0 ;
	while(capacity>0 && weight[j]<=capacity){
			total+=values[j];
			capacity-=weight[j];
		j++;
	}

	if(capacity>0){
		total += (long double)(((long double)capacity/weight[j])*values[j]);
	}
	cout.precision(10);
	cout<<total<<endl;
return 0;
}