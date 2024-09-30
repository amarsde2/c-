#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2;
struct q{
  int idx;
  int l;
  int r;
};
q qa[N];
int qlen;

bool compare(q a, q b) {    
    if(a.l / qlen == b.l / qlen){
        return a.r > b.r;
    }
    return a.l < b.l;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
       cin >> a[i];
    }

    int queries;
    cin >> queries;
    qlen = sqrtl(n);
    for(int i = 0; i < queries; i++){
       int l, r;
       cin >> l >> r;
       qa[i].idx = i;
       qa[i].l = l;
       qa[i].r = r;
    }
    
    sort(qa, qa + queries, compare);
    
    vector<int > ans(queries);
    int curr_l = 0, curr_r = -1;
    int l,r;
    int curr_sum = 0;
    for(int i = 0; i < queries; i++){
        l = qa[i].l;
        r = qa[i].r;
        l--; r--;  
        while(curr_r< r){
            curr_sum += a[++curr_r];
        }
        while(curr_l > l){
            curr_sum += a[--curr_l];
        }

        while(curr_l < l){
            curr_sum -= a[curr_l++];
        }

        while(curr_r > r){
            curr_sum -= a[curr_r--];
        }

        ans[i] = curr_sum;
    }


    for(int i = 0;  i < queries; i++){
         cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}