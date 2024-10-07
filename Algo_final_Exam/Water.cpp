#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> container(const vector<int>& h) {
    int n = h.size();
    
    priority_queue<pair<int, int>> pq;

    
    for (int i = 0; i < n; ++i) {
        pq.push({h[i], i});
    }

  
    pair<int, int> first_t = pq.top(); pq.pop();
    pair<int, int> second_s = pq.top(); pq.pop();

   
    if (first_t.second < second_s.second) {
        return {first_t.second, second_s .second};
    } else {
        return {second_s.second, first_t.second};
    }
}

int main() {
    int test;
    cin >>test; 

    while (test--) {
        int n;
        cin >> n; 
        vector<int> h(n);
 
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        pair<int, int> res = container(h);
        cout << res.first << " " << res.second << endl; 
    }

    return 0;
}
