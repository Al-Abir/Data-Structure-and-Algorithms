#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    

    bool adj[1001][1001];
    
    memset(adj, false, sizeof(adj)); 

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
    }

    int q;
    cin >> q; 
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        
        if (u == v || adj[u][v]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
