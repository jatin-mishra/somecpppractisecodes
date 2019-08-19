#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

short get_last_digit(long long term){
	int position = term % 60;
	int first = 0;
	int second = 1;
	int res = position;
	for(int i=1;i<position;i++){
		res = (first + second)%10;
		first = second;
		second = res;
	}
	return res%10;
}




int main(){
	long long term;
	cin>>term;

	short first = get_last_digit(term);
	short second = get_last_digit(term+1);

	cout<<(first*second)%10;

	return 0;
}