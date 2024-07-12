#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
     cin.ignore();
    queue<string> q1;
    string name;
    int cmd;

    for (int i = 0; i < q; i++) {
        cin >> cmd;
        if (cmd == 0) {
            cin >> name;
            q1.push(name);
        } else if (cmd == 1) {
            if (q1.empty()) {
                cout << "Invalid" << endl;
            } else {
                cout << q1.front() << endl;
                q1.pop();
            }
        }
    }

    return 0;
}
