#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int a[N], tree[N];


void buildTree(int node, int low, int high){
    if(low == high){
        tree[node] = a[low];
        return;
    }

    int mid = (low + high) / 2;

    buildTree(2*node, low, mid);
    buildTree(2*node + 1, mid+1, high);

    tree[node] = max(tree[2*node], tree[2*node + 1]);
}

int query(int node, int low, int high, int l, int r){
    if(low > r || high < l){
        return INT_MIN;
    }

    if(low <= l && high >= r){
        return tree[node];
    }

    int mid = (low + high) / 2;

    int q1 = query(2*node, low, mid, l, r);
    int q2 = query(2*node + 1,mid+1,high, l, r);

    return max(q1,q2);
}




void update(int node, int low, int high, int idx, int value){
    if(low == high){
        a[low] = value;
        tree[node] = value;
        return;
    }

    int mid = (low + high) / 2;

    if(idx <= mid){
        update(2*node,low, mid, idx, value);
    } else{
        update(2*node+1, mid+1, high, idx, value);
    }

    tree[node] = max(tree[2*node], tree[2*node+1]);
}


signed main(){
    int n; 
    cin >> n;

    for(int i=0; i<n; i++){
       cin >> a[i];
    }

    buildTree(1, 0, n-1);

    while(1){
        int type;
        cin >> type;
        
        if(type == -1) {
            break;
        } else if(type == 1){
            int low, high;
            cin >> low >> high;
            cout << query(1, 0, n-1, low, high) << endl;
        } else if(type == 2){
            int idx, value;
            cin >> idx >> value;
            update(1,0, n-1,idx, value);
             cout << query(1, 0, n-1, 0, n-1) << endl;
        }
    }

    return 0;
}