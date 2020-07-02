#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    ll n, k;

    cin >> n >> k;
    
    if(n%2){
        if(n/2+1 < k){
            //K will be even
            cout << 2*(k-n/2-1) << endl;
        } else {
            //K will be odd
            cout << 2*k-1 << endl;
        } 
        
    } else{
        if(n/2 < k){
            //K will be even
            cout << 2*(k-n/2) << endl;
        } else {
            //K will be odd
            cout << 2*k-1 << endl;
        } 
    }
    
    
    return 0;
}

//g++ -std=c++11 -O2 -Wall 318A.cpp -o out
// 1 3 5 7 2 4 6 -> 6