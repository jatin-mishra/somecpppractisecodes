#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
int n,count=0;
cin>>n;

	count += n/10;
	n = n%10;
	// cout<<"after 10 "<<count<<" remains to "<<n<<endl;
	count += n/5;
	n = n%5;
	// cout<<"after 5 "<<count<<" remains to "<<n<<endl;
	count+=n;
	cout<<count;

	return 0;
}