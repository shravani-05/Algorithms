#include<bits/stdc++.h>
using namespace std;
void selection(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
       int min = i;
       for(int j = i+1; j < n; j ++){
            if(arr[j] < arr[min]){
                min = j;
            }
       }
       if(min != i){
        swap(arr[min],arr[i]);
       }
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

    selection(arr,n);

    cout<<endl;
    cout<<"Elements after sorting: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}