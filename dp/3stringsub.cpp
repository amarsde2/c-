#include<bits/stdc++.h>
using namespace std;
const int N  =1e2+2;

int dp[N][N][N];

int logestcommon(string &s1, string &s2, string &s3, int i , int j , int k){
    
    if(i == 0 || j == 0 || k == 0) 
      return 0;
   
    if(dp[i][j][k] != -1) 
       return dp[i][j][k];
       
    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
         return 1 + logestcommon(s1, s2, s3, i-1, j-1, k-1);
    } else{
        int l = logestcommon(s1,s2, s3, i-1,j, k);
        int r = logestcommon(s1,s2, s3, i,j-1, k);
        int m = logestcommon(s1,s2, s3, i,j, k-1);
        return max({l, r, m});
    } 
}

int main(){
    memset(dp, -1, sizeof(dp));

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n1 = s1.size();
    int n2=  s2.size();
    int n3 = s3.size();

    cout << logestcommon(s1, s2, s3, n1, n2, n3) << endl;
}