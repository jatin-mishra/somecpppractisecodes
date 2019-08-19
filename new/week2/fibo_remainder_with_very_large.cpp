#include <iostream>
#include <string>

using namespace std;

// pisano period
long get_period(int dvdr){
	long a=0,b=1;
	for(long i=2;i>0;i++){
		b=(a+b);
		a = b-a;
		if(b%dvdr == 1  && a%dvdr ==0 )
			return i-1;
		b=b%dvdr;
		a=a%dvdr;
	}
}


long long get_remainder(long long position , int dvdr){

long long first=0;
long long second=1;
long long res=position;
// cout<<first<<" ";
for(int i=1;i<position;i++){
	// cout<<second%dvdr<<" ";
	res = (first + second)%dvdr;
	first = second;
	second=res;

}

return res%dvdr;

}


int main(){

	long long term ;
	int dvdr;
	long long position,remainder;
	long period;
	cin>>term;
	cin>>dvdr;

// returns the pisano period
	period = get_period(dvdr);

	// cout<<"pisano period is : "<<period;

	position = term % period;

	remainder = get_remainder(position,dvdr);

	cout<<remainder;

	return 0;
}

