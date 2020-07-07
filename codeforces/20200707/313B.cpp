#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int sums[100000];


void print_array(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    sums[n-1] = 0;
    for (int i = n-2; i >= 0; i--)
    {   
        sums[i] = sums[i+1] + (s[i] == s[i+1]);   
    }
    // print_array(sums, n);
    int m, l, r;
    cin >> m;
    while (m--)
    {
        cin >> l >> r;
        cout << sums[l-1]-sums[r-1] << endl;
    }
    
}

//g++ -std=c++11 -O2 -Wall 313B.cpp -o out