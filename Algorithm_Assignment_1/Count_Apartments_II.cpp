#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

// Directions for moving up, right, down, and left
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1}; 

bool valid(int x, int y) {
    // Check if (x, y) is within the grid, is a room ('.'), and is not visited
    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.' && !vis[x][y]) {
        return true;
    }
    return false;
}

// Perform DFS and count the number of rooms in the current apartment
int dfs(int si, int sj) {
    vis[si][sj] = true; // Mark the current cell as visited
    int room_count = 1; // Start with the current room

    // Explore all 4 directions
    for (int i = 0; i < 4; i++) {
        int ci = si + dx[i]; // New row index
        int cj = sj + dy[i]; // New column index

        if (valid(ci, cj)) {
            room_count += dfs(ci, cj); // Recursively count all connected rooms
        }
    }

    return room_count; // Return the total number of rooms in this apartment
}

int main() {
    cin >> n >> m;

    // Input the building map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> room_counts; // To store the number of rooms in each apartment

    // Iterate over each cell in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If a room is found and not visited yet, it means a new apartment is discovered
            if (graph[i][j] == '.' && !vis[i][j]) {
                int rooms = dfs(i, j); // Perform DFS to count the rooms in this apartment
                room_counts.push_back(rooms); // Store the room count
            }
        }
    }

    // Sort the room counts in ascending order
    sort(room_counts.begin(), room_counts.end());

    // Output the room counts
    if (room_counts.empty()) {
        cout << 0 << endl; // If there are no apartments, output 0
    } else {
        for (int count : room_counts) {
            cout << count << " ";
        }
        cout << endl;
    }

    return 0;
}
