#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int a[N];
pair<int, int>tree[4*N];


void buildTree(int node, int low, int high){
    if(low == high){
        tree[node].first = a[low];
        tree[node].second = 1;
        return;
    }

    int mid = (low + high) / 2;

    buildTree(2*node, low, mid);
    buildTree(2*node + 1, mid+1, high);

    if(tree[2*node].first < tree[2*node + 1].first){
        tree[node].first = tree[2*node].first;
        tree[node].second = tree[2*node].second;
    } else if(tree[2*node].first > tree[2*node +1].first){
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node+1].second;
    } else{
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node].second + tree[2*node+1].second;
    }
}

pair<int, int> query(int node, int low, int high, int l, int r){
    if(low > r || high < l){
        pair<int, int> p;
        p.first = 1.e9+2;
        p.second = -1;
        return p;
    }

    if(low >= l && high <= r){
       return tree[node];
    }

    int mid = (low + high) / 2;

    pair<int,int> q1 = query(2*node, low, mid, l, r);
    pair<int,int> q2 = query(2*node + 1,mid+1,high, l, r);

    if(q1.first < q2.first){
       return q1;
    } else if(q1.first > q2.first){
       return q2;
    } else{
       pair<int, int> q3;
       q3.first =q1.first;
       q3.second = q1.second + q2.second;
       return q3;
    }
}

void update(int node, int low, int high, int idx, int value){
    if(low == high){
        a[low] = value;
        tree[node].first = value;
        tree[node].second = 1;
        return;
    }

    int mid = (low + high) / 2;

    if(idx <= mid){
        update(2*node,low, mid, idx, value);
    } else{
        update(2*node+1, mid+1, high, idx, value);
    }

    if(tree[2*node].first < tree[2*node + 1].first){
        tree[node].first = tree[2*node].first;
        tree[node].second = tree[2*node].second;
    } else if(tree[2*node].first > tree[2*node +1].first){
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node+1].second;
    } else{
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node].second + tree[2*node+1].second;
    }
}


signed main(){
    int n, m; 
    cin >> n >> m;

    for(int i=0; i<n; i++){
       cin >> a[i];
    }

    buildTree(1, 0, n-1);

    while(m--){
        int type, op1 ,op2;
        cin >> type >> op1 >> op2;
        
        if(type == -1) {
            break;
        } else if(type == 1){
            update(1,0, n-1,op1, op2);
        } else if(type == 2){
           pair<int, int>  ans = query(1, 0, n-1, op1, op2);
           cout << ans.first << " " << ans.second << endl;
        }
    }

    return 0;
}