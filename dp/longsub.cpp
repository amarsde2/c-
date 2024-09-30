#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;

int DP[N];

int longSubsque(vector<int> &a, int n){
    
    if(DP[n] != -1) 
       return DP[n];

    DP[n] = 1;

    for(int i = 0; i < n; i++){
        if(a[n] > a[i]){
            DP[n] = max(DP[n], longSubsque(a,i) + 1 );
        }
    }

    return DP[n];
}

int main(){
    for(int i = 0; i < N; i++){
        DP[i] = -1;
    }
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }

    int dpp[n];

    for(int i = 0; i < n; i++){
       dpp[i] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                dpp[i] = max(dpp[i], 1+dpp[j]);
                 
            }
        }
        ans = max(ans, dpp[i]);
    }

    cout << ans << endl;

    //cout << longSubsque(a, n-1) << endl;
}