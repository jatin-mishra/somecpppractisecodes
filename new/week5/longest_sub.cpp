#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;


int max(int a,int b,int c){
int num = (a<b)?b:a;
if(num>c)
	return num;
return c;
}

int edit_distance(int first[],int second[] ,int f,int s){
int arr[f+1][s+1];
for(int i=0;i<=f;i++){
	for(int j=0;j<=s;j++){
		if(j==0 || i==0)
			arr[i][j]=0;
		else if(first[i-1]==second[j-1])
			arr[i][j]=arr[i-1][j-1]+1;
		else
			arr[i][j] = max(arr[i-1][j],arr[i][j-1],arr[i-1][j-1]);
	}
}
return arr[f][s];
}

int main(){
int n,m;
cin>>n;
int first[n];
for(int i=0;i<n;i++)
cin>>first[i];

cin>>m;
int second[m];
for(int i=0;i<m;i++)
	cin>>second[i];
int distance = edit_distance(first,second,n,m);
cout<<distance<<endl;
return 0;
}