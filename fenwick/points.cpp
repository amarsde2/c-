#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> bit;
vector<int> a;

int query(int num){
    int ans = 0;
    while(num > 0){
        ans += bit[num];
        num -= num & (-num); // Move to the parent node
    }
    return ans;
}

void update(int idx, int val){
    while(idx <= n){
        bit[idx] += val;
        idx += idx & (-idx); // Move to the next node
    }
}

int main(){
    cin >> n;
    bit = vector<int>(n+1, 0); // Initialize with 0 (1-based indexing)
    a = vector<int>(n+1);

    // Reading array values and updating the BIT
    for(int i = 1; i <= n; i++){
        cin >> a[i]; // Now using 1-based indexing
        update(i, a[i]);
    }

    int q;
    cin >> q;

    while(q--){
        int c; 
        cin >> c;

        if(c == 1){
            int l, r;
            cin >> l >> r;
            // Query sum from l to r (1-based inclusive)
            int ans = query(r) - query(l-1);
            cout << ans << endl;
        }

        if(c == 2){
            int index, value;
            cin >> index >> value;
            // Update the difference in value
            update(index, -a[index]); // Remove old value
            a[index] = value;
            update(index, value); // Add new value
        }
    }

    return 0;
}
