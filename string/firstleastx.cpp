#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int a[N];
int tree[4*N];

// Function to build the segment tree
void buildTree(int node, int low, int high){
    if(low == high){
        tree[node] = a[low];  // Set leaf node with the value from array
        return;
    }

    int mid = (low + high) / 2;
    buildTree(2*node, low, mid);
    buildTree(2*node + 1, mid+1, high);

    tree[node] = max(tree[2*node], tree[2*node+1]);  // Combine results of children
}

// Function to update the tree by changing the value at index `idx`
void update(int node, int low, int high, int idx, int value){
    if(low == high){
        a[low] = value;
        tree[node] = value;
        return;
    }

    int mid = (low + high) / 2;
    if(idx <= mid){
        update(2*node, low, mid, idx, value);
    } else {
        update(2*node + 1, mid+1, high, idx, value);
    }

    tree[node] = max(tree[2*node], tree[2*node+1]);  // Recalculate the parent node
}

// Function to query the maximum value in the range [l, r]
int query(int node, int low, int high, int l, int r){
    if(l > high || r < low){  // Outside the range
        return -N;  // Return a minimum value to ensure it doesn't affect max calculation
    }

    if(low >= l && high <= r){  // Inside the query range
        return tree[node];
    }

    int mid = (low + high) / 2;

    int q1 = query(2*node, low, mid, l, r);  // Query the left child
    int q2 = query(2*node + 1, mid+1, high, l, r);  // Query the right child

    return max(q1, q2);  // Return the maximum of both
}

int main(){
    int n, m;
    cin >> n >> m;

    // Input the initial array
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Build the initial segment tree
    buildTree(1, 0, n-1);

    // Process the queries
    while(m--){
        int type;
        cin >> type;

        if(type == 1){
            int key, value;
            cin >> key >> value;
            // Update the element at index `key`
            update(1, 0, n-1, key, value);
        } else {
            int x;
            cin >> x;

            // Find the leftmost index where the value in the array is >= x
            int ans = -1;
            int low = 0;
            int high = n-1;

            while(low <= high){
                int mid = (low + high) / 2;
                // Query the maximum in range [low, mid]
                if(query(1, 0, n-1, low, mid) >= x){
                    ans = mid;  // This could be the valid answer, but we continue searching left
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if(ans == -1){
                cout << "-1" << endl;  // If no index is found
            } else {
                cout << ans << endl;  // Output the leftmost index
            }
        }
    }

    return 0;
}
