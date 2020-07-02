#include <bits/stdc++.h>


typedef long long ll;

using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[5] = {0,0,0,0,0};
    int holder;
    while(n--){
        cin >> holder;
        arr[holder]++;
    }
    int ans = 0;
    ans += arr[4];
    //3+1
    ans += arr[3];
    arr[1] -= arr[3];
    if(arr[1] < 0)
        arr[1] = 0;

    //2+2
    ans += arr[2]/2;
    //Checking if there's a 2 after
    arr[2] = arr[2]%2;

    //2+1+1
    if(arr[2]){
        ans++;
        if(arr[1] >=2){
            arr[1] -= 2;
        }else if(arr[1]){
            arr[1]--;
        }
    }

    //1+1+1+1
    ans += arr[1]/4;
    if(arr[1]%4){
        ans++;
    }

    cout << ans << "\n";
}

//g++ -std=c++11 -O2 -Wall 158B.cpp -o out