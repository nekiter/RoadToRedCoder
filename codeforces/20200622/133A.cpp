#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    string p;

    cin >> p;

    if(p.find('H') != string::npos || p.find('Q') != string::npos|| p.find('9')!= string::npos ){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}

//g++ -std=c++11 -O2 -Wall 133A.cpp -o out