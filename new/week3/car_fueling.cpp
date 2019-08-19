#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int binary_search(int pump_position[] ,int start,int last, int to_search,int const_last){
	if(last>=start){
		int mid = (start + last )/2;

		if(pump_position[mid]>to_search)
			return binary_search(pump_position,start,mid-1,to_search,const_last);
		else
			return binary_search(pump_position,mid+1,last,to_search,const_last);
	}

return last;
}



int main(){
	int size , capacity,last_station;
	cin>>last_station;
	cin>>capacity;
	cin>>size;

	int pump_position[size+1];
	for(int i=0;i<size;i++){
		cin>>pump_position[i];
	}
	pump_position[size]=last_station;

	int pos = -1,index,count=0,cap = capacity;

	// if you want to put car at first then make :
	// capacity+=pump_position[0];
	while(pos < size+1){
		index = binary_search(pump_position,pos+1,size,capacity,size);
		if(index == pos && (pump_position[index+1]>capacity)){
			// cout<<"cannot go farward now "<<endl;
			count=-1;
			break;
		}
		pos=index;
		// cout<<pump_position[index]<<" ";
		if(index!=size)
			count++;
		capacity = pump_position[index] + cap;
		if(index==size)
			break;
	}

	cout<<count<<endl;

}