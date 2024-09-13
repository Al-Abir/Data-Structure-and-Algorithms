#include <bits/stdc++.h>
#define ll long long
const ll INF = 1e18 + 5;
using namespace std;

int main() {
    ll n, e;
    cin >> n >> e;

    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        adj[i][i] = 0;
    }


    for (int i = 0; i < e; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][k] < INF && adj[k][j] < INF) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }


    int q;
    cin >> q;

    while (q--) {
        int src, dest;
        cin >> src >> dest;
        if (adj[src][dest] == INF)
            cout << -1 << endl;
        else
            cout << adj[src][dest] << endl;
    }

    return 0;
}
