#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "aabebcdd";
    string s2 = s1;

    int m = s1.size(), n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}
