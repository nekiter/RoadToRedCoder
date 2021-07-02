#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */
const int MAX_EDGES = 3001;
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

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<pair<int, int>> sortedVertices;
    // O(V)
    for(int i = 0; i < g_weight.size(); i++){
        sortedVertices.push_back(make_pair(g_weight[i], i));
    } 
    // O(VLogV)
    sort(sortedVertices.begin(), sortedVertices.end());

    for (int i = 0; i < MAX_EDGES; i++){
        edges[i] = -1;
    }

    int treeWeight = 0;
    for(int i = 0; i < sortedVertices.size(); i++) {
        int treeSize = addVertice(g_from[sortedVertices[i].second],g_to[sortedVertices[i].second]);
        if(treeSize == 0) continue; // Ignore vertices that creates cycles
        treeWeight += sortedVertices[i].first;
        if(treeSize*-1 >= g_nodes) break; // Tree already contains all nodes
    }
    return treeWeight;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    fout << res << "\n";

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
