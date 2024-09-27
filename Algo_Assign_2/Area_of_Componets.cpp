#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1}; 

int bfs(int x, int y, vector<vector<char>>& g, vector<vector<bool>>& vis, int n, int m) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    
    int area = 0;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        area++;
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '.' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    return area;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int minArea = INT_MAX;
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' && !vis[i][j]) {
                int area = bfs(i, j, g, vis, n, m);
                minArea = min(minArea, area);
                found = true;
            }
        }
    }
    
    if (found) {
        cout << minArea << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}
