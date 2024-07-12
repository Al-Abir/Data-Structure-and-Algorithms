#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n,m;
    cin >> n>> m;
    stack<int> s1;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        s1.push(val);
    }
    queue<int> q1;
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        q1.push(value);
    }

    if (s1.size() != q1.size()) {
        cout << "NO" << endl;
        return 0;
    }

    bool isSame = true;
    while (!s1.empty() && !q1.empty()) {
        if (s1.top() != q1.front()) {
            isSame = false;
            break;
        }
        s1.pop();
        q1.pop();
    }

    if (isSame==true) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

