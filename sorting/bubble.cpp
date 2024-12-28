#include<bits/stdc++.h>
using namespace std;
void bubble(vector<int> &arr,int n){
    bool swapped;
    for(int i = 0; i < n; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped != true){
            break;
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

    bubble(arr,n);

    cout<<endl;
    cout<<"Elements after sorting: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}