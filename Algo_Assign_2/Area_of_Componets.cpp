#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dx[] = {-1, 1, 0, 0}; // Up, Down
int dy[] = {0, 0, -1, 1}; // Left, Right

// BFS function to find the area of each component
int bfs(int startX, int startY, vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    
    int area = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        area++;
        
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '.' && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
    
    return area;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int minArea = INT_MAX;
    bool foundComponent = false;
    
    // Traverse the grid and find components
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                int area = bfs(i, j, grid, visited, n, m);
                minArea = min(minArea, area);
                foundComponent = true;
            }
        }
    }
    
    // Output the result
    if (foundComponent) {
        cout << minArea << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}
