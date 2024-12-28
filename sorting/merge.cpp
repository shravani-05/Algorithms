#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>& arr,int low, int mid, int high){
    vector<int> left(arr.begin() + low , arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1 , arr.begin() + high + 1);

    int i = 0 , j = 0, k = low;

    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }

    }
    while(i < left.size()){
            arr[k++] = left[i++];
    }

    while(j < right.size()){
            arr[k++] = right[j++];
    }
}
void mergeSort(vector<int> &arr, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid + 1, high);

    merge(arr,low,mid,high);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> arr;
    cout<<"Enter the elements in the array: ";
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    mergeSort(arr,0,n-1);

    cout<<endl;
    cout<<"Elements after sorting: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}