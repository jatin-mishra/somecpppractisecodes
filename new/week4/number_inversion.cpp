#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

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

int merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k,count=0,index; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    for(int j=r;j>m;j--){
        index=get_last(arr,l,m,arr[j]);
        count+=m-index;
    }
  
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

    return count;
} 
  

int merge_sort(int arr[], int first, int last) 
{ 
    if (first<last) 
    { 
        
        int mid = (first+last)/2; 
       int a = merge_sort(arr, first, mid); 
        int b = merge_sort(arr, mid+1, last); 
        int c = merge(arr, first, mid, last); 
        return a + b + c;
    } 
    return 0;
} 

 
int main(){
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int inversions = merge_sort(arr,0,n-1);
	cout<<inversions<<endl;
	return 0;
}

