#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b, unordered_map<string, bool>& memo) {
    if (a.size() != b.size()) return false;
    if (a == b) return true;
    
    string key = a + "|" + b; // Unique key for the pair (a, b)
    if (memo.find(key) != memo.end()) return memo[key];

    int n = a.size();
    for (int i = 1; i < n; i++) {
        // Check for split and swap
        if ((solve(a.substr(0, i), b.substr(0, i), memo) && 
             solve(a.substr(i), b.substr(i), memo)) ||
            (solve(a.substr(0, i), b.substr(n - i), memo) && 
             solve(a.substr(i), b.substr(0, n - i), memo))) {
            memo[key] = true;
            return true;
        }
    }

    memo[key] = false;
    return false;
}

int main() {
    string s1 = "great";
    string s2 = "rgeat";

    unordered_map<string, bool> memo; // Memoization map

    if (solve(s1, s2, memo)) {
        cout << "String is scrambled!" << endl;
    } else {
        cout << "String is not scrambled!" << endl;
    }

    return 0;
}
e