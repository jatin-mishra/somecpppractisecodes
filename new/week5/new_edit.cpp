#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;


int min(int a,int b,int c){
int num = (a<b)?a:b;
if(num<c)
	return num;
return c;
}

int edit_distance(string first,string second ,int f,int s){
int arr[f+1][s+1];
for(int i=0;i<=f;i++){
	for(int j=0;j<=s;j++){
		if(j==0)
			arr[i][j]=i;
		else if(i==0)
			arr[i][j]=j;
		else if(first[i-1]==second[j-1])
			arr[i][j]=arr[i-1][j-1];
		else
			arr[i][j] = min(arr[i-1][j],arr[i][j-1],arr[i-1][j-1])+1;
	}
}
return arr[f][s];
}

int main(){
string first,second;
cin.tie(0);
ios::sync_with_stdio(NULL);
getline(cin,first);
getline(cin,second);
int distance = edit_distance(first,second,first.length(),second.length());
cout<<distance<<endl;
return 0;
}