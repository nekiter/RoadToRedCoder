#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

ll arr[200001];

void print_array(ll arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int t;
    int n, k;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] %= k;
        }

        sort(arr, arr+n);
        //All numbers already k multiple
        if(!arr[n-1]){
            cout << 0 << endl;
            continue;
        }

        ll ans = -1;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if(!arr[i]) continue;
            if(arr[i] != arr[i-1]){
                ans = max(ans, 1ll*k*count+ (k-arr[i]) );
                count = 0;
            }else{
                count++;
            }
        } 
        cout << ans+1 << endl;

   
    }
    
}

//g++ -std=c++11 -O2 -Wall 1374D.cpp -o out