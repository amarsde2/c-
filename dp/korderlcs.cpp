#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> a;
vector<int> b;
int dp[2000][2000][7];

int solveLong(int i, int j, int k){
    if( i == n || j == m) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int c1(0), c2(0), c3(0);
    if(a[i] == b[j]){
        c1 = 1 + solveLong(i+1, j+1, k);
    }

    if(k > 0){
        c2  = 1 + solveLong(i+1, j+1, k-1);
    }

    c3 = max(solveLong(i+1, j, k), solveLong(i, j+1, k));

    return max({c1, c2, c3});
}

int main(){
   
    memset(dp,-1,sizeof(dp));

    cin >> n >> m >> k;

    a = vector<int>(n);
    b = vector<int>(m);
    
    for(auto &i : a){
        cin >> i;
    }

    for(auto &j: b){
        cin >> j;
    }

    cout << solveLong(0, 0, k) << endl;

    return 0;
}