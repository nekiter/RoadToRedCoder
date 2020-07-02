#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int t;
    ll x, y, n;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> n;

        ll current_mod = n%x;

        if(current_mod == y){
            cout << n << endl;
        } else if(current_mod > y){
            int ans = x*(n/x) + y;
            cout << ans << endl;
        } else{
            int ans = x*( (n/x) -1) + y;
            cout << ans << endl;
        }
    }
    

}

//g++ -std=c++11 -O2 -Wall A.cpp -o out