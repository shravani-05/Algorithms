#include<bits/stdc++.h>
using namespace std;
void naiveMatching(string text,string pat){
    int n = text.length();
    int m = pat.length();
    for(int i = 0; i <= n-m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(text[i+j] != pat[j]){//to compare the string ans the pattern one letter at 
                                    //a timeee.
                break;
            }
        }
        if(j == m){//and finally if j has iterated  == m times then pattern found at the index 
            cout<<"Pattern found at index " << i <<endl;
        }
    }
}
int main(){
    string text,pat;
    cout<<"Enter the string text: ";
    cin>>text;

    cout<<"Enter the string pattern: ";
    cin>>pat;

    naiveMatching(text,pat);
    return 0;
}