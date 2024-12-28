#include<bits/stdc++.h>
using namespace std;
#define d 256
#define q 101
void rabinkarp(string text, string pat){
    int n = text.length();
    int m = pat.length();
    int i,j;
    int p = 0, t = 0;
    int h = 1;

    //calculating the rolling hash value for sliding window
    for(i = 0; i < m-1; i++){
        h = (h * d)% q;
    }

    //calculating the hash value of pattern and text
    for(i = 0; i < m; i++){
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
    }

    //uptill this text pattern and rolling hash values are caluculated 
   
    for(i = 0; i < n -m; i++){
        if(p == t){
            for(j = 0; j < m; j++){
                if(text[i+j] != pat[j]){
                    break;
                }
            }
            if(j == m){
                cout<<"Pattern found at index: "<<i;
            }
        }
        //this is the sliding window protocol formula
        if(i < n - m){
            t = (d* (t - text[i] * h) + text[i + m]) % q;
                if(t < 0){
                    t = (t + q);
                }
        }
    }

}
// t = ( d* (t - text[i]*h) + text[i+m])
int main(){
    string text,pat;
    cout<<"Enter the string text: ";
    cin>>text;

    cout<<"Enter the string pattern: ";
    cin>>pat;

    rabinkarp(text,pat);
    return 0;
}