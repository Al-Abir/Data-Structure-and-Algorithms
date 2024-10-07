#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int w, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));


    for (int i = 1; i <= n; i++) {
        for (int cap = 0; cap <= w; cap++) {
       
            dp[i][cap] = dp[i - 1][cap];

       
            if (wt[i - 1] <= cap) {
                dp[i][cap] = max(dp[i][cap], dp[i - 1][cap - wt[i - 1]] + val[i - 1]);
            }
        }
    }

    
    return dp[n][w];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w; 

        vector<int> wt(n), val(n); 
        for (int i = 0; i < n; i++) cin >> wt[i]; 
        for (int i = 0; i < n; i++) cin >> val[i]; 

        cout << knapsack(n, w, wt, val) << endl; 
    }

    return 0;
}
