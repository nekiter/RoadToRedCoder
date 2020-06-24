#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int n;
    cin >> n;
    int columns[n];
    for (int i = 0; i < n; i++)
    {
        cin >> columns[i];
    }
    sort(columns, columns+n);

    for (int i = 0; i < n; i++)
    {
        cout << columns[i] << " ";
    }
    cout << endl;
}

//g++ -std=c++11 -O2 -Wall 405A.cpp -o out