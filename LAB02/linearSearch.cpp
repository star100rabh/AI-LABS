#include<iostream>
using namespace std;
int main(){
    int arr[]={1,4,7,9,1,3,5,11,23,45,26,75};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ele;
    cout<<"Enter element : ";
    cin>>ele;
    int found=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==ele) found=1;
    }
    if(found==-1) cout<<"Element not found!";
    else cout<<"Element found!";
    return 0;
}