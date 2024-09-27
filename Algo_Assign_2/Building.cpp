#include <bits/stdc++.h>
#define pi pair<int, long long>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

  
    bool unionSets(int x, int y) {
        int rtx = find(x);
        int rty = find(y);

        if (rtx == rty)
            return false;

   
        if (rank[rtx] > rank[rty]) {
            parent[rtx] = rty;
        } else if (rank[rtx] < rank[rty]) {
            parent[rtx] = rty;
        } else {
            parent[rty] = rtx;
            rank[rtx]++;
        }
        return true;
    }
};


long long kruskal(int n, vector<pair<long long, pi>> &edges) {

    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    long long mincost = 0;
    int edgCt = 0;

    for (const auto &edge : edges) {
        long long weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (uf.unionSets(u, v)) {
            mincost += weight;
           edgCt++;
        }

  
        if (edgCt == n - 1)
            break;
    }

    if (edgCt != n - 1)
        return -1;

    return mincost;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<pair<long long, pi>> edges; 

    for (int i = 0; i < e; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--;
        b--;
        edges.push_back({w, {a, b}});
    }

    long long mincost = kruskal(n, edges);
    if (mincost == -1)
        cout << "-1" << endl;
    else
        cout << mincost << endl;

    return 0;
}
