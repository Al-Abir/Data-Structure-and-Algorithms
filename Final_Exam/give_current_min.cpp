#include <iostream>
#include <queue>
#include <map>
using namespace std;


void priority(priority_queue<int, vector<int>, greater<int>>& pq, map<int, int>& freq) {
    while (!pq.empty() && freq[pq.top()] == 0) {
        pq.pop();
    }
}

void currentMin(priority_queue<int, vector<int>, greater<int>>& pq, map<int, int>& freq) {
   priority(pq, freq);
    if (pq.empty()) {
        cout << "Empty" << endl;
    } else {
        cout << pq.top() << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        pq.push(value);
        freq[value]++;
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int command;
        cin >> command;
        
        if (command == 0) {
          
            int x;
            cin >> x;
            pq.push(x);
            freq[x]++;
            currentMin(pq, freq);
        } else if (command == 1) {
            currentMin(pq, freq);
        } else if (command == 2) {
          
            priority(pq, freq);
            if (!pq.empty()) {
                int minValue = pq.top();
                pq.pop();
                freq[minValue]--;
            }
            currentMin(pq, freq);
        }
    }
    
    return 0;
}
