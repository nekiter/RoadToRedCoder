#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/pj/2019/f1/secreta/
int main(){
    int n, current_number;
    int last_number = -1;
    int ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> current_number;
        if(current_number != last_number){
            ans++;
            last_number = current_number;
        }       
    }
    cout << ans << endl;
    
}
