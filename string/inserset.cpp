#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int tree[4*N];

struct t {
    int l;
    int r;
    int idx;
};

// Function to update the tree by changing the value at index `idx`
void update(int node, int low, int high, int idx, int value){
    if(low == high){
        tree[node] = value;
        return;
    }

    int mid = (low + high) / 2;
    if(idx <= mid){
        update(2*node, low, mid, idx, value);
    } else {
        update(2*node + 1, mid+1, high, idx, value);
    }

    tree[node] = tree[2*node] + tree[2*node+1];  // Recalculate the parent node
}

// Function to query the maximum value in the range [l, r]
int query(int node, int low, int high, int l, int r){
    if(l > high || r < low){  // Outside the range
        return 0;  // Return a minimum value to ensure it doesn't affect max calculation
    }

    if(low >= l && high <= r){  // Inside the query range
        return tree[node];
    }

    int mid = (low + high) / 2;

    int q1 = query(2*node, low, mid, l, r);  // Query the left child
    int q2 = query(2*node + 1, mid+1, high, l, r);  // Query the right child

    return q1+q2;  // Return the maximum of both
}

bool compare(struct t t1, struct t t2) {
   return t1.r < t2.r;
}

int main(){
    int n;
    int x;
    
    cin >> n;

    struct t t1;
    t1.l = -1;
    t1.r = -1;
    t1.idx = 0;

    vector<struct t> a(n, t1);

    for(int i = 1; i <= 2*n; i++){
        cin >> x;
        if(a[x-1].l == -1){
           a[x-1].l = i;
        } else{
            a[x-1].r = i;
        }
        a[x-1].idx = x;
    }

    sort(a.begin(), a.end(), compare);
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        ans[a[i].idx-1] = (a[i].r - a[i].l -1) - 2*query(1,0, 2*n-1, a[i].l, a[i].r);
        update(1,0, 2*n-1,a[i].l, 1);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
