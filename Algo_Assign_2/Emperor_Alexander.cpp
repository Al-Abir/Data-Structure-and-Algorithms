#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int N = 100005; 
int par[N];           
int sz[N];            


void dsu_init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = -1; 
        sz[i] = 1;   
    }
}


int dsu_find(int node) {
    if (par[node] == -1) return node; 
    return par[node] = dsu_find(par[node]);
}

// Union by size
void union_by_size(int nodeA, int nodeB) {
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);
    if (leaderA != leaderB) {
        if (sz[leaderA] > sz[leaderB]) {
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

    vector<tuple<long long, int, int>> edges; 


    for (int i = 0; i < m; i++) {
        int u, v;
        long long cost;
        cin >> u >> v >> cost;
 
        if (u != v) {
            edges.push_back({cost, u, v});
        }
    }

    sort(edges.begin(), edges.end());

    dsu_init(n);
    long long totalCost = 0;
    int edgesUsed = 0;


    for (auto &[cost, u, v] : edges) {
        if (dsu_find(u) != dsu_find(v)) {
            union_by_size(u, v);
            totalCost += cost; 
            edgesUsed++;
        }
    }


    if (edgesUsed != n - 1) {
        cout << "Not Possible" << endl;
    } else {
        cout << (m - edgesUsed) << " " << totalCost << endl; 
    }

    return 0;
}
