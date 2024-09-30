#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int len = sqrtl(n)  + 1;
    vector<int> b(len,0);

    for(int i = 0; i < n; i++){
        b[i % len] += a[i];
    }

    int sum = 0;

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;

        for(int i = l; i <= r;){
           if(i % len == 0 && i + len -1 <= r){
             sum += b[i/len];
             i += len;
           } else{
              sum += a[i];
              i++;
           }
        }

        cout << sum << endl;
    }
}