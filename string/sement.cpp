#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int a[N], tree[4*N];

// Build segment tree
void buildTree(int Node, int low, int high){
    if(low == high){
        tree[Node] = a[low];
        return;
    }

    int mid = (low + high)/2;
    buildTree(2*Node, low, mid);
    buildTree(2*Node + 1, mid+1, high);

    tree[Node] = tree[2*Node] + tree[2*Node + 1];
}

// Query sum in range [L, R]
int query(int Node, int low, int high, int L, int R){
    if(low > R || high < L){
        return 0;
    }
    if(low >= L && high <= R){
        return tree[Node];
    }

    int mid = (low + high)/2;
    int leftSum = query(2*Node, low, mid, L, R);
    int rightSum = query(2*Node + 1, mid+1, high, L, R);

    return leftSum + rightSum;
}

// Update value at index `idx` to `value`
void update(int Node, int low, int high, int idx, int value){
    if(low == high){
        tree[Node] = value;
        return;
    }

    int mid = (low + high)/2;
    if(idx <= mid){
        update(2*Node, low, mid, idx, value);
    } else {
        update(2*Node + 1, mid+1, high, idx, value);
    }

    tree[Node] = tree[2*Node] + tree[2*Node + 1];
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    buildTree(1, 0, n-1);

    // Example query
    cout << "Sum of range [1, 3]: " << query(1, 0, n-1, 1, 3) << endl;

    // Example update
    update(1, 0, n-1, 2, 10);
    cout << "Updated sum of range [1, 3]: " << query(1, 0, n-1, 1, 3) << endl;

    return 0;
}
