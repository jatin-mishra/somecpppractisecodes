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

int edit_distance(string first,string second ,vector<vector<int>> v,int f_s,int s_s){

if(f_s+1 == 0 || s_s+1 ==0)
	return (f_s+1==0)?(s_s+1):f_s+1;
else{
	if(first[f_s]==second[s_s])
		v[f_s + 1][s_s+1] = (v[f_s][s_s]!=-1)?v[f_s][s_s]:edit_distance(first,second,v,f_s-1,s_s-1);
	else{
		v[f_s][s_s+1] = (v[f_s][s_s+1]!=-1)?v[f_s][s_s+1]:edit_distance(first,second,v,f_s-1,s_s);
		v[f_s+1][s_s] = (v[f_s+1][s_s]!=-1)?v[f_s+1][s_s]:edit_distance(first,second,v,f_s,s_s-1);
		v[f_s][s_s] = (v[f_s][s_s]!=-1)?v[f_s][s_s]:edit_distance(first,second,v,f_s-1,s_s-1);
		v[f_s+1][s_s+1] = min(v[f_s][s_s],v[f_s+1][s_s],v[f_s][s_s+1]) + 1;
	}
	return v[f_s+1][s_s+1];
}
}

int main(){
string first,second;
cin.tie(0);
ios::sync_with_stdio(NULL);
 getline(cin,first);
 getline(cin,second);
vector<vector<int>> v(first.length()+1);
for(int i=0;i<first.length()+1;i++)
	v[i] = vector<int>(second.length()+1,-1);
int distance = edit_distance(first,second,v,first.length()-1,second.length()-1);
cout<<distance<<endl;

	return 0;
}