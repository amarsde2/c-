#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
vector<int>dp;
int fab(int n){
   
    if(n == 1 || n == 0)
       return 0;
    
    if(n == 2){
        return 1;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n]  = fab(n-1) + fab(n-2);
    
    return dp[n];
   
}

int main(){
    int n;
    cin >> n;
    dp = vector<int>(n+1);
    
    // tablication approach

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
}