#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;


void insertion_sort(long long int users[][2],int number_of_user){

int start,end,j;

    for(int i=1;i<number_of_user;i++){
        j = i-1;

        start = users[i][0];
        end = users[i][1];

        while(j>=0 && users[j][0]>start){
            users[j+1][0] = users[j][0];
            users[j+1][1] = users[j][1];
            j--;
        }

        users[j+1][0] = start;
        users[j+1][1] = end;
    }


}

int main(){
    int n;
    cin>>n;
    long long int tenant[n][2];
    for(int i=0;i<n;i++)
        cin>>tenant[i][0]>>tenant[i][1];

    insertion_sort(tenant,n);

    // for(int i=0;i<n;i++){
    //     cout<<tenant[i][0]<<" "<<tenant[i][1]<<endl;
    // }
    long long int save_points[n],j,min;
    int count=0;
    for(int i=0;i<n;i++){
        min = tenant[i][1];
        j=i+1;
        // cout<<"for started -----------------"<<endl;
        for(j=i+1;j<n && tenant[j][0]<=min;j++){
            min = (min>tenant[j][1])?tenant[j][1]:min;
            // cout<<"min is : "<<min<<"j is : "<<j<<endl;
        }
        save_points[count]=min;
        count++;
        i=j-1;
    }

    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<<save_points[i]<<" ";
    }
    return 0;
}