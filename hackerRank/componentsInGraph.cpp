#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */
const int NUMBER_OF_EDGES = 15001*2;
int edges[NUMBER_OF_EDGES] = {};

int findParent(int node) {
    if(edges[node] < 0) return node;
    edges[node] = findParent(edges[node]); //Collapsing find
    return edges[node];
}

bool addVertice(int u, int v) { //Union
    int parentU = findParent(u);
    int parentV = findParent(v);
    if(parentV == parentU) return false; //It's a cycle!

    //Ranking union
    if(edges[parentU] < edges[parentV]){
        edges[parentU] += edges[parentV];
        edges[parentV] = parentU;
    } else {
        edges[parentV] += edges[parentU];
        edges[parentU] = parentV;
    }
    return true;
}

vector<int> componentsInGraph(vector<vector<int>> gb) {
    for (int i = 0; i < NUMBER_OF_EDGES; i++){
        edges[i] = -1;
    }
    // O( Vertices)
    for (int i = 0; i < gb.size(); i++){
        addVertice(gb[i][0], gb[i][1]);
    }
    int larger = -2;
    int smaller = -INFINITY;
    for (int i = 0; i < NUMBER_OF_EDGES; i++){
        // cout << edges[i] << " ";
        if(edges[i] >= -1) continue;
        if(edges[i] >= smaller) smaller = edges[i];
        if(edges[i] <= larger) larger = edges[i];
    }
    // cout << endl;
    return {smaller*-1, larger*-1};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        gb[i].resize(2);

        string gb_row_temp_temp;
        getline(cin, gb_row_temp_temp);

        vector<string> gb_row_temp = split(rtrim(gb_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int gb_row_item = stoi(gb_row_temp[j]);

            gb[i][j] = gb_row_item;
        }
    }

    vector<int> result = componentsInGraph(gb);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
