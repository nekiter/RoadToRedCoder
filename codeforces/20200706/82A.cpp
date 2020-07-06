#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int n, p = 0;
    cin >> n;
    string names[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    while(5*pow(2,p) <= n){
        p++;
    }

    int ans = n/pow(2,p);
    

    cout << names[ans] << endl;
}

//g++ -std=c++11 -O2 -Wall 82A.cpp -o out