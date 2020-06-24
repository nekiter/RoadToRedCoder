#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    int puzzles[m];

    for (size_t i = 0; i < m; i++)
    {
        cin >> puzzles[i];
    }

    sort(puzzles, puzzles+m);

    int ans = 1001;
    n--;
    for (size_t i = 0; i < m-n; i++)
    {
        if(puzzles[i+n] - puzzles[i] < ans)
            ans = puzzles[i+n] - puzzles[i];
    }

    cout << ans << endl;
    
}

//g++ -std=c++11 -O2 -Wall 337A.cpp -o out