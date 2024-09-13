#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

// Directions for moving up, right, down, and left
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1}; 

bool valid(int x, int y) {
    // Check if (x, y) is within the grid and is a room ('.') and not visited
    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.' && !vis[x][y]) {
        return true;
    }
    return false;
}

void dfs(int si, int sj) {
    vis[si][sj] = true; // Mark the current cell as visited

    // Explore all 4 directions
    for (int i = 0; i < 4; i++) {
        int ci = si + dx[i]; // New row index
        int cj = sj + dy[i]; // New column index

        if (valid(ci, cj)) {
            dfs(ci, cj); // Recursively visit all connected rooms
        }
    }
}

int main() {
    cin >> n >> m;

    // Input the building map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int cnt = 0; // To count the number of apartments

    // Iterate over each cell in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If a room is found and not visited yet, it means a new apartment is discovered
            if (graph[i][j] == '.' && !vis[i][j]) {
                dfs(i, j); // Perform DFS to mark the entire connected apartment
                cnt++; // Increment the apartment count
            }
        }
    }

    cout << cnt << endl; // Output the total number of apartments
    return 0;
}
