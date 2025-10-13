#include<bits/stdc++.h>
using namespace std;


int main(){
    string s1 = "hello";
    string s2 = "hemli";
    
    int m = s1.size(), n = s2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int ans = 0;
    for(int i  = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(s1[i-1] == s2[j-1]){
              dp[i][j] = 1 + dp[i-1][j-1];
              ans = max(ans, dp[i][j]);
            } else{
              dp[i][j]  = 0;
            }
        }
    }

    cout << ans << endl; 

    return 0;
}