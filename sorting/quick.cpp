#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<=j){
        while(arr[i] <= pivot && i <= high){
        i++;
    }

        while(arr[j] > pivot && j >= low){
        j--;
    }

        if(i<j){
            swap(arr[i],arr[j]);
    }
    }
    swap(arr[low],arr[j]);
    return j;

}
void quick(int arr[], int low, int high){
    if(low<high){
        int pindex = partition(arr,low,high);

        quick(arr,low,pindex - 1);
        quick(arr,pindex + 1, high);

    }
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

    quick(arr,0,n-1);
    cout<<"Elements after sorting: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}