#include <iostream>
#include <set>
using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        set<int> UniNum; 
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            UniNum.insert(num); 
        }

        bool first = true; 
        for (auto it = UniNum.begin(); it != UniNum.end(); ++it) {
            if (!first) {
                cout << " "; 
            }
            cout << *it;
            first = false; 
        }
        cout << endl; 
    }

    return 0;
}