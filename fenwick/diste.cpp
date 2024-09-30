#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
struct q {
    int idx;
    int l;
    int r;
};
q qa[N];
int qlen;

bool compare(q a, q b) {
    if (a.l / qlen == b.l / qlen) {
        return a.r > b.r; // Sort by decreasing r when l is the same
    }
    return a.l < b.l; // Sort by l
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int queries;
    cin >> queries;
    qlen = sqrt(n); // Block size for Mo's algorithm
    for (int i = 0; i < queries; i++) {
        int l, r;
        cin >> l >> r;
        qa[i].idx = i;
        qa[i].l = l - 1; // Convert to 0-based indexing
        qa[i].r = r - 1; // Convert to 0-based indexing
    }

    sort(qa, qa + queries, compare); // Sort queries using Mo's order

    vector<int> ans(queries);
    int curr_l = 0, curr_r = -1; // Current range
    int curr_ans = 0;
    vector<int> freq(10 * N, 0); // Frequency array, initialize to zero

    for (int i = 0; i < queries; i++) {
        int l = qa[i].l;
        int r = qa[i].r;

        // Expand the range to the right
        while (curr_r < r) {
            curr_r++;
            freq[a[curr_r]]++;
            if (freq[a[curr_r]] == 1) {
                curr_ans++;
            }
        }
        
        // Contract the range from the right
        while (curr_r > r) {
            if (freq[a[curr_r]] == 1) {
                curr_ans--;
            }
            freq[a[curr_r]]--;
            curr_r--;
        }

        // Expand the range to the left
        while (curr_l > l) {
            curr_l--;
            freq[a[curr_l]]++;
            if (freq[a[curr_l]] == 1) {
                curr_ans++;
            }
        }

        // Contract the range from the left
        while (curr_l < l) {
            if (freq[a[curr_l]] == 1) {
                curr_ans--;
            }
            freq[a[curr_l]]--;
            curr_l++;
        }

        ans[qa[i].idx] = curr_ans; // Store the answer for the current query
    }

    for (int i = 0; i < queries; i++) {
        cout << ans[i] << " "; // Output results
    }

    cout << endl;

    return 0;
}
