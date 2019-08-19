#include <iostream>
#include <string>

using namespace std;

long fibo(long array[],int term){

if(array[term] == 0 ){
	if(term<=1)
		return term;
	array[term]=(long)(fibo(array,term-1)+fibo(array,term-2));
}

return array[term];
}



int main(){

	int n;
	cin>>n;

	long array[n+1] = {0};

	long number = fibo(array,n);
	cout<<number;

}