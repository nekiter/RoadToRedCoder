#include <bits/stdc++.h>


typedef long long ll;


using namespace std;

int arr[2*10000000];
int rest[2*10000000];

int main(){
    int n,k,x;
    int t;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i]%k != 0){
                rest[j] = arr[i]%k;
                j++;
            } 

        }
        x = 0;
        int moves = 0;
        int aux = 0;
        while(j != aux){
            moves++;
            for (int i = 0; i < j; i++)
            {
                if(rest[i] == -1)
                    continue;
                if((rest[i] + x)%k == 0 ){
                    x++;
                    aux++;
                    rest[i] = -1;
                    break;
                }
            }
                x++;            
        }
        cout << moves << endl;
        
    }
    
}

//g++ -std=c++11 -O2 -Wall D.cpp -o out