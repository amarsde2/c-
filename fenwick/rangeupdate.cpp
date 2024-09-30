#include<bits/stdc++.h>
using namespace std;


int query(int num, int bits[], int n){
    int ans = 0;
    while(num > 0){
        ans += bits[num];
        num -= num & (-num); // Move to the parent node
    }
    return ans;
}

void update(int idx, int val, int bits[], int n){
    while(idx <= n){
        bits[idx] += val;
        idx += idx & (-idx); // Move to the next node
    }
}

int main(){
    int m;
    cin >> m;
    while(m--){
      int n;
      cin >> n;
      int bits[n+10] = {0};      
      int u;
      cin >> u;
      while(u--){
        int l,r, inc;
        cin >> l >> r >> inc;
        l++; r++;
        update(l, inc, bits ,n);
        update(r+1, -inc, bits ,n);
      }

      int q;
      cin >>  q;
      while(q--){
        int w;cin >> w;
        w++;
        cout << query(w, bits, n) << endl;
      }
    }
  
    return 0;
}
