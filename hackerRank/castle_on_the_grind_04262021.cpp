#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumMoves function below.
bool canMove(vector<string> grid, int x, int y){
    if( x < 0 || x >= grid.size()){
        return false;
    }
    if( y < 0 || y >= grid.size()){
        return false;
    }
    if(grid[x][y] == 'X' ){
        return false;
    }

    return true;
}

void moveOnGrid(
    vector<string> grid, 
    int startX, 
    int startY, 
    int currentDistance, 
    pair<int,int> direction,
    queue<pair<int, int>>& toVisit,
    vector<vector<int>> &distanceMatrix) {
    int nextX = startX + direction.first;
    int nextY = startY + direction.second;

    bool moved = false;
    while( canMove(grid, nextX, nextY) ){
        if(distanceMatrix[nextX][nextY] != -1 && distanceMatrix[nextX][nextY] < currentDistance)  
            break;
        nextX = nextX + direction.first;
        nextY = nextY + direction.second;
        moved = true;
        distanceMatrix[nextX - direction.first][nextY - direction.second] = currentDistance;
        toVisit.push(pair<int,int>(nextX - direction.first, nextY - direction.second));
    }
  
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    vector<vector<int>> distance(grid.size(), vector<int>(grid.size(),-1));

    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    
    distance[startX][startY] = 0;
    while (q.size() > 0) {
        pair<int, int> currentNode = q.front();
        int currentDistance = distance[currentNode.first][currentNode.second] + 1;
        q.pop();

        // Checking all neighbours
        //left
        moveOnGrid(
            grid, 
            currentNode.first, 
            currentNode.second, 
            currentDistance,
            pair<int,int>(-1,0),
            q,
            distance);
        
        //right
        moveOnGrid(
            grid, 
            currentNode.first, 
            currentNode.second, 
            currentDistance,
            pair<int,int>(+1,0),
            q,
            distance);
        
        //up
        moveOnGrid(
            grid, 
            currentNode.first, 
            currentNode.second, 
            currentDistance,
            pair<int,int>(0,-1),
            q,
            distance);
        
        //down
        moveOnGrid(
            grid, 
            currentNode.first, 
            currentNode.second, 
            currentDistance,
            pair<int,int>(0,+1),
            q,
            distance);

        if(distance[goalX][goalY] != -1){
            break;
        }
    }

    // for(int i = 0; i < grid.size(); i++){
    //     for(int j = 0; j < grid.size(); j++){
    //         if(i == startX && j == startY)
    //             cout << " S ";
    //         else if(i == goalX && j == goalY)
    //             cout << " G ";
    //         else if(grid[i][j] == 'X')
    //             cout << " X ";
    //         else if(distance[i][j]/10 < 1 && distance[i][j] >= 0)
    //             cout << " " << distance[i][j] << " ";
    //         else
    //             cout << distance[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // cout <<  distance[goalX][goalY]<< endl;
    // cout << q.size() << endl;
    return distance[goalX][goalY];
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
