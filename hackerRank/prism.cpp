#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
 return v1[2] < v2[2];
}

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */
const int MAX_EDGES = 4501500; // 3001*3000/2
int edges[MAX_EDGES] = {};

int findParent(int node) {
    if(edges[node] < 0) return node;
    edges[node] = findParent(edges[node]); //Collapsing find
    return edges[node];
}

int addVertice(int u, int v) {
    int parentU = findParent(u);
    int parentV = findParent(v);
    if(parentV == parentU) return 0; // It's a cycle
    // ranked union
    if(edges[parentV] < edges[parentU]){
        edges[parentV] += edges[parentU];
        edges[parentU] = parentV;
        return edges[parentV];
    } else {
        edges[parentU] += edges[parentV];
        edges[parentV] = parentU; 
        return  edges[parentU];
    }
}


int prims(int n, vector<vector<int>> vertices, int start) {
    // O(VLogV)
    sort(vertices.begin(), vertices.end(), sortcol);
    for (int i = 0; i < MAX_EDGES; i++){
        edges[i] = -1;
    }

    int treeWeight = 0;
    for(int i = 0; i < vertices.size(); i++) {
        // cout << "Vertice " << vertices[i][0] << " " << vertices[i][1] << endl;
        int treeSize = addVertice(vertices[i][0], vertices[i][1]);
        if(treeSize == 0) continue; // Ignore vertices that creates cycles
        treeWeight += vertices[i][2];
        if(treeSize*-1 >= n) break; // Tree already contains all nodes
    }
    return treeWeight;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));

    int result = prims(n, edges, start);

    fout << result << "\n";

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
