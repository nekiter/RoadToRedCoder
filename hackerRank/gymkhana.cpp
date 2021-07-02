//https://www.thehuxley.com/problem/186
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MAX_PAIR = 1001;
int pairs[MAX_PAIR] = {};

int findParent(int n) {
    if(pairs[n] < 0) return n;
    pairs[n] = findParent(pairs[n]);
    return pairs[n];
}
int addVertice(int u, int v) {
    int parentU = findParent(u);
    int parentV = findParent(v);
    if(parentV == parentU) return 0; // It's a cycle
    // ranked union
    if(pairs[parentV] < pairs[parentU]){
        pairs[parentV] += pairs[parentU];
        pairs[parentU] = parentV;
        return pairs[parentV];
    } else {
        pairs[parentU] += pairs[parentV];
        pairs[parentV] = parentU; 
        return  pairs[parentU];
    }
}

int main() {
    for (int i = 0; i < MAX_PAIR; i++){
        pairs[i] = -1;
    }

    int n, m;

    cin >> n >> m;

    int i, j;

    while (m > 0){
        m--;
        cin >> i >> j;
        addVertice(i, j);        
    }

    vector<int> parents;
    for (i = 1; i < n+1; i++){
        int parent = findParent(i);
        bool duplicated = false;
        // cout << " ================ " << endl;
        for(j = 0; j < parents.size(); j++){
            // cout << parents[j] << " ";
            if(parents[j] == parent){
                duplicated = true;
                break;
            }
        }
        if(!duplicated){
            parents.push_back(parent);
        }
        // cout << endl;
    }
    cout << parents.size() << endl;
    
}

//g++ -std=c++11 -O2 -Wall gymkhana.cpp -o out