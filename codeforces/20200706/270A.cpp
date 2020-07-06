#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int t;
    cin >> t;

    int a;
    while (t--)
    {
        cin >> a;
        if(360%(180-a)){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
    
}

//g++ -std=c++11 -O2 -Wall 270A.cpp -o out