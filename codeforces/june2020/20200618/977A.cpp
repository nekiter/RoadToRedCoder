#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int n, k;

    cin >> n >> k;

    while(k--){
        if(n%10)
            n--;
        else
            n /= 10;
    }

    cout << n << "\n";
}

//g++ -std=c++11 -O2 -Wall 977A.cpp -o out