#include<bits/stdc++.h>
using namespace std;
void insertion(vector<int> &arr, int n){
   for(int i = 1; i < n; i++){
    int temp = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]>temp){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
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

    insertion(arr,n);

    cout<<endl;
    cout<<"Elements after sorting: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}