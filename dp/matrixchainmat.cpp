#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int> &costs, int i, int j, vector<vector<int>>& dp){
    
    if(i >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i; k <= j-1; k++){
       int temp = minCost(costs, i, k, dp) + minCost(costs,k+1, j,dp) + costs[i-1] * costs[k] * costs[j];
       if(temp < ans){
        ans = temp;
       }
    }

    return dp[i][j] = ans ;

}

int main(){
    vector<int> ar = {40,20,30,10,30};
    
    int n = ar.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));

    int ans = minCost(ar, 0, ar.size()-1, dp);
    
    cout << ans << endl;

    return 0;
}