#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int t;
    cin >> t;
    ll n;
    
    while (t--)
    {
        cin >> n;

        int ans = 0;
        while(n != 1){
            ans++;
            
            if(n%3 != 0){
                ans = -1;
                break;
            }

            if(n%6 == 0){
                n = n/6;
            } else{
                n = n * 2;
            }

        }
        cout << ans << endl;
        
    }
    
}

//g++ -std=c++11 -O2 -Wall B.cpp -o out