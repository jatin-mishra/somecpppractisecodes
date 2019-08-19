#include<iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

vector<int> call(vector<int> v,int n){
	int index=0;
	while(n>2){
		v.push_back(n);
		n/=2;
		index++;
	}
	return v;
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	vector<int>it =  call(v,n);
	it.shrink_to_fit();
	for(int i=0;i<it.size();i++)
		cout<<it[i]<<" ";
} 