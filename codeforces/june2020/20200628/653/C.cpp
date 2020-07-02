#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int t,n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int moves = 0;
        int open_parenthesis = 0;
        for (size_t i = 0; i < n; i++)
        {
            if(s[i] == ')'){
                if(open_parenthesis <= 0){
                    moves++;
                } 
                else{
                    open_parenthesis--;
                }
            }
            else{
                open_parenthesis++;
            }
        }
        cout << moves << endl;
    }
    
}

//g++ -std=c++11 -O2 -Wall C.cpp -o out