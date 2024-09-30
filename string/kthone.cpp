#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int a[N];
int tree[4*N];

// Function to build the segment tree
void buildTree(int node, int low, int high){
    if(low == high){
        tree[node] = a[low];  // Set leaf node with the binary value from array
        return;
    }

    int mid = (low + high) / 2;
    buildTree(2*node, low, mid);
    buildTree(2*node + 1, mid+1, high);

    tree[node] = tree[2*node] + tree[2*node+1];  // Combine results of children
}

// Function to update the tree by toggling the value at index `idx`
void update(int node, int low, int high, int idx){
    if(low == high){
        // Toggle the value of the leaf node
        if(a[low] == 1){
            tree[node] = 0;
            a[low] = 0;
        } else {
            tree[node] = 1;
            a[low] = 1;
        }
        return;
    }

    int mid = (low + high) / 2;
    if(idx <= mid){
        update(2*node, low, mid, idx);
    } else {
        update(2*node + 1, mid+1, high, idx);
    }

    tree[node] = tree[2*node] + tree[2*node+1];  // Recalculate the parent node
}

// Function to query the index of the `key`th one in the array
int query(int node, int low, int high, int key){
    if(low == high){
        return low;  // Leaf node reached, return its index
    }

    int mid = (low + high) / 2;
    
    if(key < tree[2*node]){
        return query(2*node, low, mid, key);  // If the key is within the left child
    } else {
        return query(2*node+1, mid+1, high, key - tree[2*node]);  // Move to right child
    }
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
        int type, key;
        cin >> type >> key;

        if(type == 1){
            // Toggle the element at index `key`
            update(1, 0, n-1, key);
        } else {
            // Query the index of the `key`th one
            if(key >= tree[1]) {  // Check if the `key` is valid (no more than total ones)
                cout << -1 << endl;  // Return -1 if invalid
            } else {
                cout << query(1, 0, n-1, key) << endl;  // Output the index of `key`th one
            }
        }
    }

    return 0;
}
