#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    // Adjacency list representation for the graph
    vector<int> adj[n];

    // Reading edges
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q;
    cin >> q;

    // Processing each query
    for (int i = 0; i < q; i++) {
        int node;
        cin >> node;

        // If the node has no connected nodes
        if (adj[node].empty()) {
            cout << "-1" << endl;
        } else {
            // Sort the connected nodes in descending order
            sort(adj[node].rbegin(), adj[node].rend());

            // Print the connected nodes
            for (int connected_node : adj[node]) {
                cout << connected_node << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

