#include <bits/stdc++.h>
using namespace std;

int totalSubset(vector<int>& a, int totalSum) {
    int n = a.size();


    
    vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, 0)); 
    

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            if (a[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }   
    }

    return dp[n][totalSum];
}

int main() {
    vector<int> arr = {1, 1, 2, 3};
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int diff = 1;
    totalSum = (diff+ totalSum) /2;
    int ans = totalSubset(arr, totalSum);
    cout << ans << endl; // Output should be 1
    return 0;
}
