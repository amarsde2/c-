#include <bits/stdc++.h>
using namespace std;

// Check if the substring s[i..j] is a palindrome
bool isPalindrome(const string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int findMinimumCut(string &s, int i, int j, vector<vector<int>> &dp) {
    if (i >= j || isPalindrome(s, i, j)) return 0; // No cuts needed

    if (dp[i][j] != -1) return dp[i][j]; // Return cached result

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int cuts = findMinimumCut(s, i, k, dp) + findMinimumCut(s, k + 1, j, dp) + 1;
        ans = min(ans, cuts);
    }

    return dp[i][j] = ans; // Cache result
}

int main() {
    string s = "absbacaac";
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1)); // DP table for memoization
    cout << findMinimumCut(s, 0, n - 1, dp) << endl;

    return 0;
}
