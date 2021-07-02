#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Graph {
    public:
        vector<int> nodes;
        vector<vector<int>> edges;
        int amountNodes;
        Graph(int n) {
            amountNodes = n;
            for (int i = 0; i < n; i++) {
                nodes.push_back(0);
                vector<int> aux;
                for (int j = 0; j < n; j++){
                    aux.push_back(0);
                }
                edges.push_back(aux);
            }
        }
    
        void add_edge(int u, int v) {
            edges[u][v] = 1;
            edges[v][u] = 1;
        }
    
        vector<int> shortest_reach(int start) {
            // Pair<Node, distance>
            queue<int> nextToVisit;
            
            int currentNode = start;
            nextToVisit.push(currentNode);
            while(!nextToVisit.empty()) {
                
                currentNode = nextToVisit.front();
                nextToVisit.pop();
                for(int i = 0; i < amountNodes; i++){
                    //Has connection?
                    if(edges[currentNode][i] != 0) {
                        // Already visited?
                        if(nodes[i] == 0) {
                            nodes[i] = nodes[currentNode] + 6;
                            nextToVisit.push(i);
                        }
                    }
                }
            }

            return nodes;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                if(distances[i] == 0)
                    cout << "-1" << " ";
                else
                    cout << distances[i] << " ";
            } 
        }
        cout << endl;
    }
    
    return 0;
}
