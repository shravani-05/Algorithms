#include<iostream>
#include<vector>
using namespace std;

void printsubset(vector<int>& set){
    cout<<"{";
    for(int num : set){
        cout<<num<<",";
    }
    cout<<"}";
}
void findsubset(vector<int>& set, int targetsum, vector<int>& currentsubset, int i, int currentsum){

    //base case
    if( targetsum == currentsum){
        printsubset(currentsubset);
        return;
    }

    //edge case
    if( i>set.size() || currentsum > targetsum){
        return;
    }

    currentsubset.push_back(set[i]);
    return findsubset(set,targetsum,currentsubset,i+1,currentsum+set[i]);

    currentsubset.pop_back();
    return findsubset(set,targetsum,currentsubset,i+1,currentsum);
}
int main(){
    int n,targetsum;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> set(n);
    cout<<"Enter the elements in the set: ";
    for(int i= 0; i< n;i++){
        cin>>set[i];
    }

    cout<<"Enter the targetsum: ";
    cin>>targetsum;

    vector<int> currentsubset;
    cout<<"The subset of target "<<targetsum<<": ";

    findsubset(set,targetsum,currentsubset,0,0);

    return 0;
}