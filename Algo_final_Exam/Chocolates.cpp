#include <iostream>
#include <vector>
using namespace std;

bool divide(vector<int>& c, int n) {
    int total = 0;
   
    for (int i = 0; i < n; i++) {
        total += c[i]; 
    }

  
    if (total % 2 != 0) {
        return false;
    }

    int target = total / 2;

  
    vector<bool> dp(target + 1, false);
    dp[0] = true;

   
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= c[i]; j--) {
            dp[j] = dp[j] || dp[j - c[i]];
        }
    }

    return dp[target];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        if (divide(c, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
