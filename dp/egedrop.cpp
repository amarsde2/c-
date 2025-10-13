#include<bits/stdc++.h>
using namespace std;

int findMinimalThreshold(int f, int e) {
    vector<vector<int>> dp(e + 1, vector<int>(f + 1));

    // If there are no floors, zero drops are needed.
    for (int i = 0; i <= e; i++) {
        dp[i][0] = 0;
    }

    // If there's one egg, only one drop is needed.
    for (int j = 0; j <= f; j++) {
        dp[1][j] = j;
    }

    // Fill the dp table
    for (int i = 2; i <= e; i++) {
        for (int j = 1; j <= f; j++) {
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= j; k++) {
                int temp = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }

    return dp[e][f];
}

int main() {
    int f = 5; // number of floors
    int e = 3; // number of eggs

    cout << findMinimalThreshold(f, e) << endl;

    return 0;
}
