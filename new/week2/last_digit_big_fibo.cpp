#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int get_last_at(long long position){
	long long first = 0;
	long long second = 1;
	long long res = position;

	for(int i=1;i<position;i++){
		res = (first + second)%10;
		first = second;
		second = res;
	}

	return res%10;
}



int main(){
	long long n;
	long long m;
	int last_digit;

	cin>>m;
	cin>>n;

	long long position = n % 60;
	long long position2 = m % 60;
	// given = position-1;

	if(n==m){
		last_digit = get_last_at(n%60);
	}

	else{
		int fn = get_last_at(position);
		int fn_minus_1 = get_last_at(position<1?0:position-1);
		int fm_plus_1 = get_last_at(position2+1);
	

		last_digit = 2*fn + fn_minus_1 - fm_plus_1;
		last_digit = last_digit<0?10+last_digit:last_digit;
	}

	// cout<<"at "<<position<<" last digit is: "<<get_last_at(position)<<endl;
	// cout<<"at "<<given<<" last digit is: "<<get_last_at(given)<<endl;
	// // cout<<
	// cout<<"at "<<m+1<<" last digit is: "<<get_last_at(position2+1)<<endl;
	// cout<<last_digit<<endl;
	

	cout<<last_digit%10;

	return 0;

}