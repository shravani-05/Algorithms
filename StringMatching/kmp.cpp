#include<iostream>
#include<vector>
#include<string>
using namespace std;
void computeLPSarray(string pat,vector<int> &lps){
    int length = 0;
    lps[0] = 0;

    int i = 1;

    while(i < pat.length()){
        if(pat[i] == pat[length]){
            length++;
            lps[i] = length;
            i++;
        }
        else{
            if(length != 0){
                length = lps[length -1];
            }
            else{
                i++;
            }
        }
    }
}
void kmp(string text, string pat){
    int n = text.length();
    int m = pat.length();

    vector<int> lps(m,0);
    computeLPSarray(pat,lps);

    int i = 0;
    int j = 0;

    while(i < n){
        if(pat[j] == text[i]){
            i++;
            j++;
        }
        if(j == m){
            cout<<"Patter found at index : "<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i<n && pat[j] != text[i]){
            
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                     i++;
                }
            }
        
        
    }
}
int main(){
    string text,pat;
    cout<<"Enter the text string: ";
    cin>>text;

    cout<<"Enter the pattern string: ";
    cin>>pat;

    kmp(text,pat);

    return 0;
}