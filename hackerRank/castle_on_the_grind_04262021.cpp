#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    
    int distance[grid.size()][grid.size()];
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.size(); j++){
            distance[i][j] = -1;
        }
    }
    
    distance[startX][startY] = 0;
    while (q.size() > 0) {
        pair<int, int> currentNode = q.front();
        int currentDistance = distance[currentNode.first][currentNode.second];
        q.pop();
        
        // Checking all neighbours
        //left
        if(currentNode.first - 1 >= 0){
            if(distance[currentNode.first - 1][currentNode.second] == -1 && grid[currentNode.first - 1][currentNode.second] != 'X'){
                distance[currentNode.first - 1][currentNode.second] = currentDistance+1;
                q.push(make_pair(currentNode.first - 1, currentNode.second));
            }            
        } 
        
        //right
        if(currentNode.first + 1 < grid.size()){
            if(distance[currentNode.first + 1][currentNode.second] == -1  && grid[currentNode.first + 1][currentNode.second] != 'X'){
                distance[currentNode.first + 1][currentNode.second] = currentDistance+1;
                q.push(make_pair(currentNode.first + 1, currentNode.second));
            }            
        } 
        
        //up
        if(currentNode.second - 1 >= 0){
            if(distance[currentNode.first][currentNode.second - 1] == -1  && grid[currentNode.first][currentNode.second - 1] != 'X'){
                distance[currentNode.first][currentNode.second - 1] = currentDistance+1;
                q.push(make_pair(currentNode.first , currentNode.second - 1));
            }            
        } 
        
        //down
        if(currentNode.second + 1 < grid.size()){
            if(distance[currentNode.first][currentNode.second + 1] == -1 && grid[currentNode.first][currentNode.second + 1] != 'X'){
                distance[currentNode.first][currentNode.second + 1] = currentDistance+1;
                q.push(make_pair(currentNode.first, currentNode.second + 1));
            }
        } 
    }
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.size(); j++){
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return distance[goalX][goalY]/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
