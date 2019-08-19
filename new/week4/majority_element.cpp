#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;





void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
 
    for (i = 0; i < n1; i++){ 
        L[i] = arr[l + i]; 
    } 

    for (j = 0; j < n2; j++){ 
        R[j] = arr[m + 1+ j]; 
  	}

    i = 0;  
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i];
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
   
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void merge_sort(int arr[], int first, int last) 
{ 
    if (first<last) 
    { 
        
        int mid = (first+last)/2; 
        merge_sort(arr, first, mid); 
        merge_sort(arr, mid+1, last); 
        merge(arr, first, mid, last); 
    } 
} 



int get_first(int elements[],int start,int last,int to_search){
	if(last>=start){
		int mid =  (last+start)/2;
		if(elements[mid]>=to_search)
			return get_first(elements,start,mid-1,to_search);
		else
			return get_first(elements,mid+1,last,to_search);
	}
return start;

}

int get_last(int elements[],int start,int last,int to_search){
	if(last>=start){
		// cout<<"start is : "<<start<<" last is : "<<last<<endl;
		int mid = (last + start)/2;
		if(elements[mid]<=to_search)
			return get_last(elements,mid+1,last,to_search);
		else
			return get_last(elements,start,mid-1,to_search);
	}
	// cout<<"last is "<<last<<endl;
	return last;
}

int main(){
	int n,first_index,second_index;
	cin>>n;
	int elements[n];
	for(int i=0;i<n;i++)
		cin>>elements[i];

	merge_sort(elements,0,n-1);
	// for(int i=0;i<n;i++)
	// 	cout<<elements[i]<<" ";
	// cout<<endl;
	int flag=0;
	for(int i=0;i<n;i++){
		first_index = get_first(elements,i,n-1,elements[i]);
		second_index = get_last(elements,i,n-1,elements[i]);
		int num_occ = second_index-first_index+1;
		// cout<<"first_index : "<<first_index<<" and second_index : "<<second_index<<endl;
		// cout<<elements[i]<<" repeatition is : "<<num_occ<<endl;
		if(num_occ > (n/2)){
			cout<<1;
			flag=1;
			break;
		}
		i=second_index;
	}

	if(flag==0){
		cout<<0;
	}
	return 0;

}