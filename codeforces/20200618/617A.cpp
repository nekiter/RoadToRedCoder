#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int x;
    cin >> x;
    
    if(x%5)
        cout << x/5+1 << "\n";
    else
    {
        cout << x/5 << "\n";
    }
    
}

//g++ -std=c++11 -O2 -Wall 617A.cpp -o out