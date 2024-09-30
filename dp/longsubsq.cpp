#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2;

int dp[N][N];

int getLongestSubSeq(string &s1, string &s2, int n, int m){
    if(n == 0 || m == 0) return 0;
    
    if(dp[n][m] != -1) 
       return dp[n][m];
    if(s1[n-1] == s2[m-1]) 
       dp[n][m] =  1 + getLongestSubSeq(s1, s2, n-1, m-1);
    else 
       dp[n][m] =  max(getLongestSubSeq(s1, s2, n-1, m),getLongestSubSeq(s1,s2, n, m-1));
    
    return dp[n][m];
}

int main(){

    for(int  i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = -1;
        }
    }

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dpp(n+1, vector<int>(m+1,-1));

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            if(i == 0 || j == 0){
                dpp[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]){
                dpp[i][j] = dpp[i-1][j-1] + 1;
            } else{
                dpp[i][j] = max(dpp[i-1][j], dpp[i][j-1]);
            }
        }
    }
    
    cout << dpp[n][m] << endl;
}