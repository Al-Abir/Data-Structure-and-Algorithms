#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int par[N], sz[N];

// DSU Initialization
void dsu_init(int n) {
    for(int i = 1; i <= n; i++) {
        par[i] = -1;
        sz[i] = 1;
    }
}

// DSU Find with Path Compression
int dsu_find(int node) {
    if(par[node] == -1) return node;
    return par[node] = dsu_find(par[node]);
}

// DSU Union by Size
void union_by_size(int nodeA, int nodeB) {
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);
    if(leaderA != leaderB) {
        if(sz[leaderA] > sz[leaderB]) {
            par[leaderB] = leaderA;
            sz[leaderA] += sz[leaderB];
        } else {
            par[leaderA] = leaderB;
            sz[leaderB] += sz[leaderA];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<tuple<int, int, int>> edges; // {cost, city1, city2}
    
    for(int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({cost, u, v});
    }
    
    // Sort edges based on cost (for Kruskal's algorithm)
    sort(edges.begin(), edges.end());
    
    dsu_init(n); // Initialize DSU
    
    int totalCost = 0;
    int edgesUsed = 0;
    
    for(auto &[cost, u, v] : edges) {
        if(dsu_find(u) != dsu_find(v)) {
            union_by_size(u, v);  // Join the sets
            totalCost += cost;    // Add the cost to total
            edgesUsed++;          // Increment the number of edges used in MST
        }
    }
    
    // If we used fewer than (n-1) edges, it means the cities are not fully connected
    if(edgesUsed != n - 1) {
        cout << "Not Possible" << endl;
    } else {
        cout << (m - edgesUsed) << " " << totalCost << endl; // Redundant edges and minimum cost
    }

    return 0;
}

