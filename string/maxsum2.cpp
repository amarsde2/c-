#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int a[N];
struct Node{
    int maxSum;
    int preSum;
    int suffSum;
    int sum;
    Node(){
        maxSum = preSum = suffSum = sum = 0;
    }
};
vector<Node> tree(4*N);

Node merge(Node a, Node b){
    Node newNode;
    newNode.sum = a.sum + b.sum;
    newNode.preSum = max(a.preSum, a.sum + b.preSum);
    newNode.suffSum = max(b.suffSum, b.sum + a.suffSum);
    newNode.maxSum = max({a.maxSum, b.maxSum, a.suffSum + b.preSum});      
    return newNode;
}

void buildTree(int node, int low, int high){
    if(low == high){
        tree[node].maxSum = tree[node].preSum = tree[node].suffSum = tree[node].sum = a[low];
        return;
    }

    int mid = (low + high) / 2;

    buildTree(2*node, low, mid);
    buildTree(2*node+1, mid+1, high);
    
    tree[node] = merge(tree[2*node], tree[2*node+1]);
}

Node query(int node, int low, int high, int l, int r){
    if(low > r || high < l){
        Node ans;
        ans.maxSum = ans.preSum = ans.suffSum = ans.sum = INT_MIN;
        return ans;
    }

    if(low >= l && high <= r){
        return tree[node];
    }

    int mid = (low + high) / 2;
    Node left = query(2*node, low, mid, l, r);
    Node right = query(2*node+1, mid+1, high, l, r);
    return merge(left, right);
}

void update(int node, int low, int high, int idx, int value){
    if(low == high){
        a[idx] = value;
        tree[node].sum = value;
        tree[node].preSum = value;
        tree[node].suffSum = value;
        tree[node].maxSum = value;
        return;
    }

    int mid = (low + high) / 2;
   
    if(idx <= mid){
      update(2*node, low, mid, idx, value);
    } else{
      update(2*node+1, mid+1, high, idx, value);
    }
    
    tree[node] = merge(tree[2*node], tree[2*node+1]);
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
       cin >> a[i];
    }

    buildTree(1, 0, n-1);

    while(m--){
        int type, op1, op2;
        cin >> type >> op1 >> op2;

        if(type == 1){
            update(1, 0, n-1, op1, op2);
        } else if(type == 2){
            Node ans = query(1, 0, n-1, op1, op2);
            cout << ans.maxSum << " " << ans.preSum << endl;
        }
    }

    return 0;
}
