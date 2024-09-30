#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> forward(n,1), backword(n,1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] > a[j])
               forward[i] = max(forward[i], 1 + forward[j]);
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(a[i] > a[j])
                backword[i] = max(backword[i], 1 + backword[j]);
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max(ans, forward[i] + backword[i] - 1);
    }

    cout << ans << endl;

    return 0;
}