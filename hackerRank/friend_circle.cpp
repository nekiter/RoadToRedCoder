#include <bits/stdc++.h>

using namespace std;

map<long, long> ppl;

long findParent(long who){
    if(ppl.find(who) == ppl.end()){
        // Not found
        ppl[who] = -1;
    }
    if(ppl[who] < 0) return who;
    ppl[who] = findParent(ppl[who]);
    return ppl[who];
}

int addVertice(long u, long v) {
    long parentU = findParent(u);
    long parentV = findParent(v);
    if(parentV == parentU) return 0; // It's a cycle
    // ranked union
    if(ppl[parentV] < ppl[parentU]){
        ppl[parentV] += ppl[parentU];
        ppl[parentU] = parentV;
        return ppl[parentV];
    } else {
        ppl[parentU] += ppl[parentV];
        ppl[parentV] = parentU; 
        return  ppl[parentU];
    }
}

// Complete the maxCircle function below.
vector<int> maxCircle(vector<vector<int>> queries) {
    long max = 0;
    vector<int> ans;
    for(int i = 0; i < queries.size(); i++){
        int aux = addVertice(queries[i][0], queries[i][1]) * -1;
        if(aux != -1){
            if(aux > max) max = aux;
        }
        ans.push_back(max);
        cout << max << endl;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> ans = maxCircle(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
