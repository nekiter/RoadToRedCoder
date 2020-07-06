#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

ll a[1000000], b[1000000], c[1000000];

int find(int n, ll *a, ll *b){
    for (int i = 0; i < n-1; i++)
    {
        if(a[i] != b[i]){
            return a[i];
        }
    }
    return a[n-1];
}

int main(){
    int n;

    cin >> n;
    //O(N)
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //O(N)
    for (int i = 0; i < n-1; i++)
    {
        cin >> b[i];
    }
    //O(N log N)
    sort(a,a+n);
    //O(N log N)
    sort(b,b+n-1);
    //O(N)
    cout << find(n, a, b) << endl;
    //O(N)
    for (int i = 0; i < n-2; i++)
    {
        cin >> c[i];
    }
    //O(N log N)
    sort(c,c+n-2);
    //O(N)
    cout << find(n-1, b, c) << endl; 
    //Total = 5*O(N) + 3 * O(Nlog N) [N=10^5] = 5*10^5 + 3*10^5*16 = 54*10^5   
}

//g++ -std=c++11 -O2 -Wall 519B.cpp -o out