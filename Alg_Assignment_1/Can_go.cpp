#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1}; 

bool valid(int x, int y) {
   
    if (x >= 0 && x < n && y >= 0 && y < m && (graph[x][y] == '.' || graph[x][y] == 'B') && !vis[x][y]) {
        return true;
    }
    return false;
}

void dfs(int si, int sj) {
    vis[si][sj] = true; 


    for (int i = 0; i < 4; i++) {
        int ci = si + dx[i]; 
        int cj = sj + dy[i]; 

        if (valid(ci, cj)) {
            dfs(ci, cj); 
        }
    }
}

int main() {
    cin >> n >> m;

    pair<int, int> source, destination;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                source = {i, j}; 
            } else if (graph[i][j] == 'B') {
                destination = {i, j}; 
            }
        }
    }

    dfs(source.first, source.second);

 
    if (vis[destination.first][destination.second]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
