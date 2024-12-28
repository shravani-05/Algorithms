#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long karatsuba(long long x, long long y){
    if(x < 10 || y < 10){
        return x * y;//this is for handling single digit multiplication
    }

    int n = max((int)log10(x) + 1 , (int)log10(y)+1);
    int half = n / 2;
    // return n;
    // return half;

    long long tenPowerHalf = 1;
        for(int i = 0; i < half; i++){
            tenPowerHalf *= 10;
        }
    
    long long a = x / (long long)pow(10, half);
    long long b = x % (long long)pow(10, half);

    long long c = y / (long long)pow(10, half);
    long long d = y % (long long)pow(10, half);

    long long ac = karatsuba(a,c);
    // return ac;--16
    long long bd = karatsuba(b,d);
    // return bd;--2
    long long ad = karatsuba(a,d);
    // return ad;--8
    long long bc = karatsuba(b,c);
    // return bc;--4
    long long adbc = ad + bc;
    // return adbc;--12
    
    
    long long tenPowerTwoHalf = 1;
        for(int i = 0; i < 2 * half; ++i){
            tenPowerTwoHalf *= 10;
        }
    return ac * tenPowerTwoHalf + adbc * tenPowerHalf + bd;
    

}
int main(){
    long long x,y;
    cout<<"Enter the numbers x and y: ";
    cin>>x>>y;

    long long result = karatsuba(x,y);

    cout<<"The multiplication of "<<x<<" and "<<y<<" : "<<result;
}