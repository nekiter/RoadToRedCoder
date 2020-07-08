#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int t, n, a;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int count[n];
        for (int i = 0; i < n; i++)
        {
            count[i] = 0;
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            a--;
            if(!count[a]) ans++;
            count[a]++;
        }
        sort(count, count+n);

        cout << max(min(ans+1,count[n-1]-1),min(ans, count[n-1])) << endl;
        
    }
    
}

//g++ -std=c++11 -O2 -Wall 1335C.cpp -o out