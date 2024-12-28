#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int lcslen(string &str1, string& str2, int i, int j, vector<vector<int>>& dp){
    if(i < 0 || j < 0){
        return 0;
    }

    if(dp[i][j] =! -1){
        return dp[i][j];
    }

    if(str1[i] == str2[j]){
        return dp[i][j] = 1 + lcslen(str1,str2,i-1,j-1,dp);
    }
    else{
        return dp[i][j] = max(lcslen(str1,str2,i-1,j,dp) , lcslen(str1,str2,i,j-1,dp));
    }
}
int lcs(string str1, string str2){
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n, vector<int>(m,-1));
    return lcslen(str1,str2,n-1,m-1,dp);
}
int main(){
    string str1,str2;
    cout<<"Enter a string 1: ";
    cin>>str1;

    cout<<"Enter a string 2: ";
    cin>>str2;

    cout<<"Length of the longest comman subsequence : "<<lcs(str1,str2);

    return 0;
}