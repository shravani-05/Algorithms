#include<bits/stdc++.h>
using namespace std;
int linear(int arr[],int x,int n){
    for(int i = 0; i<n;i++){
        if(arr[i] == x){
            return i;
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

    int result = linear(arr,x,n);

    if(result){
        cout<<"Element found at index "<<result;
    }
    else{
        cout<<"Element not found";
    }

    return 0;
}
