#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
// int dp[N][N];
// const int INF = 999999;

// int findNumberOfWay(vector<int> &v, int n, int val){
    
//     if(val == 0) return 1;
//     if(val <  0) return 0;
   
//     if(n <= 0) return 0;

//     if(dp[n][val] != -1){
//         return dp[n][val];
//     }

//     dp[n][val] =  findNumberOfWay(v, n, val - v[n-1]) +  findNumberOfWay(v , n-1, val);

//     return dp[n][val];
// }


int main(){
    /*
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = -1;
        }
    }*/
    
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int x;
    cin >> x;
    
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            if(j - v[i-1] >= 0){
                dp[i][j] += dp[i][j - v[i-1]];
            }
            dp[i][j] += dp[i-1][j];
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}
