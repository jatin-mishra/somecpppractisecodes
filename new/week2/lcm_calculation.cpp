#include <iostream>
#include <string>

using namespace std;

long gcd(long a, long b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main(){
	long num1,num2;

	cin>>num1;
	cin>>num2;

	cout<<(long long)(num1*num2)/gcd(num1,num2);

	return 0;
}