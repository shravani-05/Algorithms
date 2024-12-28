#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int fun(vector<int>& arr,int i,int j,vector<vector<int>>& costtable, vector<vector<int>>& ktable){
    //base case
    if(i == j){
        return 0;
    }

    if(costtable[i][j] != -1){
        return costtable[i][j];
    }

    int minimum = INT_MAX;

    for(int k = i; k <= j-1; k++){
        int mini = fun(arr,i,k,costtable,ktable) + fun(arr,k+1,j,costtable,ktable) + arr[i-1]*arr[k]*arr[j];

        if(mini < minimum){
            minimum = mini;
            ktable[i][j] = k;
        }
    }

    return costtable[i][j] = minimum;

}
void printparens(int i,int j,vector<vector<int>>& ktable){
    if(i == j){
        cout<<"A"<<i;
    }
    else{
        cout<<"(";
        printparens(i,ktable[i][j],ktable);
        printparens(ktable[i][j] + 1,j,ktable);
        cout<<")";
    }

}
void matrixchainmul(vector<int>& arr, int N){
    //decalring two arrays
    vector<vector<int>> costtable(N, vector<int>(N,-1));
    vector<vector<int>> ktable(N, vector<int>(N,-1));

    int i = 1;
    int j = N-1;

    int cost = fun(arr,i,j,costtable,ktable);

    cout<<"Minimum cost of the matrices is"<<cost;
    cout<<"\nThe optimal parathesization is ";
    printparens(1,N-1,ktable);
}
int main(){
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;

    vector<int> arr(n+1);
    cout<<"Enter the dimensions of the matrices: ";
    for(int i = 0; i <= n; i++){
        cin>>arr[i];
    }

    matrixchainmul(arr,n+1);

    return 0;
}