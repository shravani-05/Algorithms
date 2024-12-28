#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int low,int high,int x){
    while(low<=high){
        int mid = low + (high-low)/2;

        if(x == arr[mid]){
            return mid;
        }
        else if(x > arr[mid]){
            return binary(arr,mid+1,high,x);
        }
        else{
            return binary(arr,low,mid-1,x);
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int x,i;
    cout<<"Enter the elements you want to search: ";
    cin>>x;

    int result = binary(arr,0,n-1,x);

    if(result !=-1){
        cout<<"Element found at index "<<result;
    }
    else{
        cout<<"Element not found";
    }

    return 0;
}