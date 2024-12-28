#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Ente the num if ele";
    cin>>n;
    
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n ;i ++){
        for(int j = 0;j < n ; j++){
            cin>>arr[i][j];
        }
    }
    
    cout<<"Ele in the arr are:";
    for(int i = 0; i < n ;i ++){
        for(int j = 0;j < n ; j++){
            cout<<arr[i][j];
        }
    }
    return 0;
}