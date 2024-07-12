#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s); 

        stack<char> st;

        for (char ch : s) {
             if (ch == '1' && !st.empty() && st.top() == '0') {
                st.pop(); 
            } else {
                st.push(ch);
            }
        }

        if (st.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

 
