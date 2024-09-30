#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+5;
const int N = 1e5+6;
vector<int> dp(N, INF);
int countSqureSum(int n){
    if(n == 0 || n == 1 || n == 2 || n == 3){
        return n;
    }
    
    if(dp[n] != INF) 
      return dp[n];

    for(int i = 1; i * i <= n; i++){
        dp[n] = min(dp[n], countSqureSum(n - i *i) + 1);
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n; 
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i = 0; i *i <= n; i++){
        for(int j = 0; i *i + j <= n; j++){
            dp[i*i + j] = min(dp[i*i + j],1 + dp[j]);
        }
    }

   cout << dp[n] << endl;

   return 0;
}
