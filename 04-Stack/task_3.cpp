#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s1;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        s1.push(val);
    }

    stack<int> s2;
    int k;
    while (!s1.empty()) {
        k = s1.top();
        s1.pop();
        s2.push(k);
    }

    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }

    return 0;
}
