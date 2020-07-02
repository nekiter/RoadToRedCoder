#include <bits/stdc++.h>

using namespace std;

//https://codeforces.com/contest/1364/problem/A


int main(){
    int t, n, x;
    
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> x;
        int a[n], sum = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            a[j] %= x;
            sum += a[j];
        }

        if(sum == 0){
            cout << "-1\n";
        }else if(sum%x != 0){
            cout << n << "\n";
        } else{
            for (int j = 0; j < n; j++)
            {
                if(a[j]%x != 0 || a[n-j-1]%x != 0){
                    cout << n-j-1 << "\n";
                    break;
                }
            }
            
        }
        
    }
    
    
}

//g++ -std=c++11 -O2 -Wall A.cpp -o out