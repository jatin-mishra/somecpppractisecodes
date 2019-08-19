#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int min(int a,int b,int c){
int num = (a<b)?a:b;
if(a<c)
	return a;
return c;
}

int alignment_game(string first,string second,int f_s,int s_s,int match,int mis,int insertion,int del){
	// cout<<first[f_s]<<" : "<<second[s_s]<<endl;
	// cout<<match<<" : "<<mis<<" : "<<insertion<<" : "<<del<<endl;
	if(f_s < first.length() && s_s < second.length()){
		if(first[f_s]==second[s_s]){
			match++;
			return alignment_game(first,second,f_s+1,s_s+1,match,mis,insertion,del);
		}else{
			if(first[f_s+1]==second[s_s+1]){
				mis++;
				return alignment_game(first,second,f_s+1,s_s+1,match,mis,insertion,del);
			}else if(first[f_s]==second[s_s+1]){
				insertion++;
				return alignment_game(first,second,f_s,s_s+1,match,mis,insertion,del);
			}else if(first[f_s+1]==second[s_s]){
				del++;
				return alignment_game(first,second,f_s+1,s_s,match,mis,insertion,del);
			}else{

				return min(alignment_game(first,second,f_s+1,s_s+1,match,mis+1,insertion,del),alignment_game(first,second,f_s,s_s+1,match,mis,insertion+1,del),alignment_game(first,second,f_s+1,s_s,match,mis,insertion,del+1));
			}
		}
	}else{
		if(f_s == first.length()){
			return mis+ insertion + del + second.length()-s_s;
		}else{			
			return mis+ insertion + del + first.length()-f_s;
		}
}
}






int main(){
string first_name;
string second_name;
getline(cin,first_name);
getline(cin,second_name);
cout<<first_name<<" : "<<second_name<<endl;
int edit_dis = alignment_game(first_name,second_name,0,0,0,0,0,0);
cout<<edit_dis<<endl;
return 0;
}