#include <iostream>
#include <cstdlib>

using namespace std;


int binary_search(int user[],int start,int last ,int to_search){

	if(last>= start){

		int mid = (start + last )/2;

		if(user[mid] > to_search)
			return binary_search(user,start,mid-1,to_search);
		else
			return binary_search(user,mid+1,last,to_search);
	}
if(user[start] == to_search)
	return start;

return last;

}




int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int k;
	cin>>k;
	int b[k],index;
	for(int j=0;j<k;j++)
		cin>>b[j];

	for(int i=0;i<k;i++){
		index = binary_search(a,0,n-1,b[i]);
		if(a[index]==b[i])
			cout<<index<<" ";
		else
			cout<<-1<<" ";
	}


	return 0;
}