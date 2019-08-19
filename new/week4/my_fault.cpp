#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


// int merge(int array[],int start1,int start2,int len1,int len2){

// int j=start2+len2-1;
// int i=start1+len1-1;
// int num,count=0;
// while(j>=start2){
//     i=start1+len1-2;
//     num = array[i+1];
//     while(i>=start1 && array[i]>array[j]){
//         array[i+1]=array[i];
//         count++;
//         i--;
//     }
//     if(array[i+1]>array[j]){
//     array[i+1]=array[j];
//     array[j]=num;
//     count++;
//     }
//     j--;
// }
// return count;

// }

// int mergeSort(int array[],int start, int last){
//     if(last>start){
//         int mid = ( start + last )/2;

//        int first =  mergeSort(array,start,mid);
//        cout<<start<<" : "<<mid<<" : "<<first<<endl;
//         int second = mergeSort(array,mid+1,last);
//        cout<<mid+1<<" : "<<last<<" : "<<second<<endl;
//         int mrg = merge(array,start,mid+1,mid-start+1,last-mid);
//     	cout<<"merge : "<<mrg<<" total: "<<first+second+mrg<<endl;
//         cout<<"\n\n\n"<<endl;
//         return first + second + mrg;

//     }
//     return 0;
// }


// int main(){
// 	int n;
// 	cin>>n;

// 	int arr[n];
// 	for(int i=0;i<n;i++)
// 		cin>>arr[i];

// 	int inversions = mergeSort(arr,0,n-1);
// 	cout<<inversions<<endl;
// 	return 0;
// }

void insertion_sort(int array[],int size){
    int j,num;
    for(int i=1;i<size;i++){
        j=i-1;
        num = array[i];

        while(j>=0 && array[j]>num){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=num;
    }

}

int search_min(int array[],int number[],int start,int last,int num){
    for(int i=start;i<=last;i++){
        if(array[i]==num && array[i]!=number[i]){
            return i;
        }
    }
}

int main(){
    int n,index,count=0;
    cin>>n;
    // int p=0;
    // while(p<=10){
    //     count=0;
    //     n=2+rand()%10;
    int number[n];
    int replica[n];
    for(int i=0;i<n;i++){
        cin>>number[i];
        // number[i]=1+rand()%10;
        replica[i]=number[i];
        // cout<<number[i]<<" ";
    }
    // cout<<endl;
    insertion_sort(number,n);

    for(int i=0;i<n;i++){
        if(number[i]!=replica[i]){
            index = search_min(replica,number,i,n-1,number[i]);
            replica[index]=replica[i];
            count++;
        }
    }
    cout<<count<<endl;
    // cout<<"\n\n\n"<<endl;
    // p++;
    // }

    return 0;

}