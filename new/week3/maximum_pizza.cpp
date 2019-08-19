#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int main(){
	long long int n,start;
	cin>>n;
	start = 1;

	int number = sqrt(2*n + 2) + 1;
	number = (number<n)?number:n;
	long long save[number];
	while(n>0){
		if(n>=start){
			save[start-1]=start;
			n=n-start;
			start++;
		}else{
			
			save[start-2]+=n;
			break;
		}
	}

	cout<<start-1<<endl;
	for(long i=0;i<start-1;i++){
		cout<<save[i]<<" ";
	}

	return 0;


}