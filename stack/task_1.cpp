#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st1;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        st1.push(val);
    }

    int m;
    cin >> m;
    stack<int> st2;
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        st2.push(val);
    }

    if (st1.size() != st2.size()) {
        cout << "NO" << endl;
        return 0;
    }

    bool isSame = true;
    while (!st1.empty() && !st2.empty()) {
        if (st1.top() != st2.top()) {
            isSame = false;
            break;
        }
        st1.pop();
        st2.pop();
    }

    if (isSame) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
