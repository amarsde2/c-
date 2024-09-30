#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Correcting the template definition for ordered set (oset)
template <class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int q;
    cin >> q;
    oset<int> myset; // Declare the ordered set

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) { // Insert operation
            int t;
            cin >> t;
            myset.insert(t);
        } 
        else if (type == 2) { // Find the k-th element (0-based)
            int t;
            cin >> t;
            // Check if the index t is valid
            if (t < myset.size()) {
                cout << *myset.find_by_order(t) << endl; // 0-based index, returns iterator to k-th smallest element
            } else {
                cout << "Index out of bounds" << endl;
            }
        } 
        else { // Count of elements strictly smaller than t
            int t;
            cin >> t;
            cout << myset.order_of_key(t) << endl; // Returns number of elements strictly smaller than t
        }
    }

    return 0;
}
