#include <bits/stdc++.h>
using namespace std;

const int s = 100000; 
bool dp[s + 1];

void calculate() {
  
    memset(dp, false, sizeof(dp));
    dp[1] = true; 


    for (int i = 1; i <= s; i++) {
        if (dp[i]) {
            if (i + 3 <= s) {
                dp[i + 3] = true; 
            }
            if (i * 2 <= s) {
                dp[i * 2] = true; 
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    calculate();

    while (T--) {
        int N;
        cin >> N;

        if (dp[N]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
