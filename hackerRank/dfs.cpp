#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxRegion' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY grid as parameter.
 */
bool canVisit(int n, int m, pair<int,int> nextPos, vector<vector<int>> visited, vector<vector<int>> grid) {
    if(nextPos.first >= n || nextPos.first < 0 || nextPos.second >= m || nextPos.second < 0)
        return false;

    if(visited[nextPos.first][nextPos.second] != 0) return false;

    if(grid[nextPos.first][nextPos.second] == 0) return false;

    return true;
}
int maxRegion(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ret = 0;
    vector<vector<int>> visited;
    for (int i = 0; i < n; i++){
        vector<int> aux;
        for (int j = 0; j < m; j++){
            aux.push_back(0);
        }
        visited.push_back(aux);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(visited[i][j] != 0 || grid[i][j] == 0) continue;
            //Run dfs
            int regionSize = 1;
            visited[i][j] = 1;
            stack<pair<int,int>> nextToVisit;
            pair<int,int> current(i,j);
            nextToVisit.push(current);
            while(!nextToVisit.empty()){
                pair<int,int> node = nextToVisit.top();
                nextToVisit.pop();
                for(int a = -1; a < 2; a++ ){
                    for(int b = -1; b < 2; b++){
                        pair<int,int> newPos(node.first+a,node.second+b);
                        if(canVisit(n, m, newPos, visited, grid)){
                            regionSize++;
                            visited[newPos.first][newPos.second] = regionSize;
                            nextToVisit.push(newPos);
                        }
                    }
                }
            }
            if(regionSize > ret) ret = regionSize;
        }
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> grid(n);

    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    int res = maxRegion(grid);

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
