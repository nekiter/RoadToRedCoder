#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0, current_size = 0, last = -1;
    int an;
    while (n--)
    {
        cin >> an;
        if(an < last){
            if(ans < current_size){
                ans = current_size;
            }
            current_size = 0;
        }
        current_size++;
        last = an;
    }

    if(ans == 0  || ans < current_size){
        ans = current_size;
    }
    cout << ans << endl;
    return 0;
    
}

//g++ -std=c++11 -O2 -Wall 580A.cpp -o out