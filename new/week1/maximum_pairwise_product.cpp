#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

int main(){
	int n;
	long long x,max1,max2;
	cin>>n;

	max1 = INT_MIN;
	max2 = INT_MIN;

	for(int i=0;i<n;i++){
		cin>>x;
		if(x>=max1){
			max2 = max1;
			max1 = x;
		}else if(x>max2){
			max2=x;
		}
	}

	

	cout<<(long long)(max1*max2)<<endl;
	

	return 0;
}