#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){
	int num;
	cin>>num;
	cout<<"enter the age in format :  year month";
	float student_age[num];
	float year , month;

	for(int i=0;i<num;i++){
		cin>>year>>month;
		student_age[i]= year + (float)(month/12);
	}

	int counted[num] = {0},save,count=0;

	for(int i=0;i<num;i++){
		if(counted[i]==0 ){
			save = student_age[i];
			for(int j=i+1;j<num;j++){
				if(counted[num]==0 && student_age[j]-save<=1 && student_age[j]-save>=-1){
					counted[num]=1;
				}
			}
			count++;
		}
	}

}