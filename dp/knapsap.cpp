#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int w[N];
int v[N];
int dp[N][N];

int getMaximumProfile(int x,int n){
    if (x <= 0 ) return 0;
    if (n <= 0) return 0;

    if(dp[x][n] != -1) return dp[x][n];
   
    if(w[n-1] > x)
       dp[x][n] = getMaximumProfile(x, n-1);
    else
       dp[x][n] = max(getMaximumProfile(x, n-1), getMaximumProfile(x-w[n-1],n-1) + v[n-1]);
    
    return dp[x][n];
}

int main(){
   
    // for(int i = 0 ; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //       dp[i][j] = -1;
    //     }
    // }
   
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int x;
   
    cin >>x;

    int dpq[n+1][x+1];

    for(int i =0 ; i < n+1; i++){
        for(int j = 0; j < x+1; j++){
            dpq[i][j] = 0;
        }
    }
  
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < x+1; j++){
            if(w[i-1] <= j){
                dpq[i][j] = max(dpq[i-1][j], dpq[i-1][j - w[i-1]] + v[i-1]);
            } else{
                dpq[i][j] = dpq[i-1][j] ;
            }
        }
    }

    cout << dpq[n][x] << endl;
    return 0;
}