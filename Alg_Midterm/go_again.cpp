#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const int MAXN = 1e5 + 5; 
class Edge {
public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

vector<ll> dis; 

int main() {
    int n, e;
    cin >> n >> e;

    dis.resize(n, INF);

    vector<Edge> EdgeList;
    for (int i = 0; i < e; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        EdgeList.push_back(Edge(u, v, c));
    }

    int src;
    cin >> src;
    src--;

    dis[src] = 0;


    for (int i = 1; i <= n - 1; i++) {
        for (const Edge& ed : EdgeList) {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] != INF && dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool negativeCycle = false;
    for (const Edge& ed : EdgeList) {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;
        if (dis[u] != INF && dis[u] + c < dis[v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative Cycle Detected" << endl;
    } else {
        int q;
        cin >> q;
        while (q--) {
            int dest;
            cin >> dest;
            dest--;
            if (dis[dest] == INF) {
                cout << "Not Possible" << endl;
            } else {
                cout << dis[dest] << endl;
            }
        }
    }

    return 0;
}
=====
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    const ll INF = 1e18;
    const int N = 1e5 + 5;


    class Edge {
    public:
        int u, v, c;
        Edge(int u, int v, int c) {
            this->u = u;
            this->v = v;
            this->c = c;
        }
    };

    vector<int> dis(N);

    int main() {
        int n, e;
        cin >> n >> e;

        vector<Edge> EdgeList;
        for (int i = 0; i < e; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            u--; v--;
            EdgeList.push_back(Edge(u, v, c));
        }

        int src;
        cin >> src;
        src--;

        for (int i = 0; i < n; i++) {
            dis[i] = INF;
        }
        dis[src] = 0;

        
        for (int i = 1; i <= n - 1; i++) {
            for (const Edge& ed : EdgeList) {  
                int u = ed.u;
                int v = ed.v;
                int c = ed.c;
                if (dis[u] != INF && dis[u] + c < dis[v]) {
                    dis[v] = dis[u] + c;
                }
            }
        }

    
        bool negativeCycle = false;
        for (const Edge& ed : EdgeList) {  
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] != INF && dis[u] + c < dis[v]) {
                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle) {
            cout << "Negative Cycle Detected" << endl;
        } else {
            int q;
            cin >> q;
            while (q--) {
                int dest;
                cin >> dest;
                dest--;
                if (dis[dest] == INF) {
                    cout << "Not Possible" << endl;
                } else {
                    cout << dis[dest] << endl;
                }
            }
        }

        return 0;
    }

