#include <bits/stdc++.h>
using namespace std;

int findMinSubsetDiff(vector<int>& a, int totalSum) {
    int n = a.size();
    
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false)); 
    
    // Base case: A sum of 0 is always possible with an empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            if (a[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }   
    }
    
    // Store possible subset sums
    vector<int> possibleSums;
    for (int i = 0; i <= totalSum / 2; i++) {
        if (dp[n][i]) {
            possibleSums.push_back(i);
        }
    }
    
    // Calculate minimum difference
    int ans = INT_MAX;
    for (int sum : possibleSums) {
        ans = min(ans, totalSum - 2 * sum);
    }
     
    return ans;
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int ans = findMinSubsetDiff(arr, totalSum);
    cout << ans << endl; // Output should be 1
    return 0;
}
