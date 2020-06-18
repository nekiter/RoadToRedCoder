#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int a, b, ans = 0;

    cin >> a >> b;

    while(a <= b){
        a *= 3;
        b *= 2;
        ans++;
    }

    cout << ans << "\n";

}

//g++ -std=c++11 -O2 -Wall 791A.cpp -o out