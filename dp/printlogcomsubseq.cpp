#include<bits/stdc++.h>
using namespace std;


int main(){
    string s1 = "acbcf";
    string s2 = "abcdaf";
    
    int m = s1.size(), n = s2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int ans = 0;
    for(int i  = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(s1[i-1] == s2[j-1]){
              dp[i][j] = 1 + dp[i-1][j-1];
            } else{
              dp[i][j]  = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i = m, j = n;
    string s;

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
           s.push_back(s1[i-1]);
           i--;
           j--;
        } else{
            if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }

    reverse(s.begin(),s.end());

    cout << s << endl;

    return 0;
}