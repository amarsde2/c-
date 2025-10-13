#include <bits/stdc++.h>
using namespace std;

int minCoinchage(vector<int>& a, int sum) {
    int n = a.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX)); 

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0; // 0 coins needed to make sum 0
    }
    
    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (a[i - 1] <= j) {
                if (dp[i][j - a[i - 1]] != INT_MAX) {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - a[i - 1]]);
                } else {
                    dp[i][j] = dp[i - 1][j]; // If using this coin doesn't work
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }   
    }
    
    return dp[n][sum] == INT_MAX ? -1 : dp[n][sum]; // Return -1 if no combination exists
}

int main() {
    vector<int> arr = {1, 2, 5};
    int sum = 5;
    int ans = minCoinchage(arr, sum);
    cout << ans << endl; // Output should be 1
    return 0;
}
