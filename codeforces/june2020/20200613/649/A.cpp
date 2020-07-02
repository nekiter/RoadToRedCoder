#include <bits/stdc++.h>

using namespace std;

//https://codeforces.com/contest/1364/problem/A

int sum(int arr[], int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int get_longest(int a[], int n, int x, int current_sum){
    if(n == 0){
        return -1;
    }
    
    if(current_sum == 0){
        return -1;
    }
    if(current_sum % x != 0){
        return n;
    } else{
        int removing_first = get_longest(&a[1], n-1, x, current_sum-a[0]);
        int removing_last = get_longest(a, n-1, x, current_sum-a[n-1]);

        if(removing_first > removing_last){
            return removing_first;
        }else{
            return removing_last;
        }
    }
}


int main(){
    int t, n, x;
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a[100000]; 
        cin >> n >> x;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            
        }
        cout << get_longest(a,n,x, sum(a, n)) << "\n";
        
    }
    
    
}

//g++ -std=c++11 -O2 -Wall A.cpp -o out