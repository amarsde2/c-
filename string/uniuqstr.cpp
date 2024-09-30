#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e3 + 2;
const int MAX_LEN = 1e5;  // Adjust as per maximum string length
vector<long long> power(MAX_LEN);

// Function to calculate hash of a string
int calculate_has(const string& w) {
    long long hash = 0;
    for (int i = 0; i < w.size(); i++) {
        hash = (hash + (w[i] - 'a' + 1) * power[i]) % MOD;
    }
    return hash;
}

int main() {
    // Precompute powers of a base (e.g., 31) modulo MOD
    int base = 31;
    power[0] = 1;
    for (int i = 1; i < MAX_LEN; i++) {
        power[i] = (power[i-1] * base) % MOD;
    }

    // Test strings
    vector<string> a = {"aa", "ab", "bb", "aa", "bb", "cc"};
    vector<int> has_er;

    // Calculate hashes for each string
    for (const auto& u : a) {
        has_er.push_back(calculate_has(u));
    }

    // Sort the hashes to find distinct hashes
    sort(has_er.begin(), has_er.end());

    // Count distinct hashes
    int distinct = 0;
    for (int i = 0; i < has_er.size(); i++) {
        if (i == 0 || has_er[i] != has_er[i-1]) {
            distinct++;
        }
    }

    // Output number of distinct strings based on their hashes
    cout << distinct << endl;

    return 0;
}
