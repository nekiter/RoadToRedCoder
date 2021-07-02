//https://www.thehuxley.com/problem/186
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MAX_BANKS = 100001;
int banks[MAX_BANKS] = {};

int findParent(int n) {
    if(banks[n] < 0) return n;
    return banks[n] = findParent(banks[n]);
}
int addVertice(int u, int v) {
    int parentU = findParent(u);
    int parentV = findParent(v);
    // if(parentV == parentU) return 0; // It's a cycle
    // ranked union
    if(banks[parentV] < banks[parentU]){
        banks[parentV] += banks[parentU];
        banks[parentU] = parentV;
        return banks[parentV];
    } else {
        banks[parentU] += banks[parentV];
        banks[parentV] = parentU; 
        return  banks[parentU];
    }
}

int main() {
    for (int i = 0; i < MAX_BANKS; i++){
        banks[i] = -1;
    }

    int n, k;

    cin >> n >> k;

    int a, b;
    char operation;

    while (k > 0){
        k--;
        cin >> operation >> a >> b;
        if(operation == 'F') addVertice(a, b);
        if(operation == 'C'){
            int parentU = findParent(a);
            int parentV = findParent(b);
            if(parentU == parentV) cout << "S" << endl;
            else cout << "N" << endl;
        }

    }

    
}

//g++ -std=c++11 -O2 -Wall fusion.cpp -o out