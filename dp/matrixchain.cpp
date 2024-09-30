#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2;
const int MODE = 1e9+2; 

int dp[N][N];

int findMinCost(vector<int> &a, int low, int high){
    if(low == high) return 0;
    
    if(dp[low][high] != -1) 
       return dp[low][high];
    
    dp[low][high] = MODE;

    for(int i = low; i < high; i++){
       dp[low][high] = min(dp[low][high], findMinCost(a, low,i) + findMinCost(a,i+1,high) + a[low-1] * a[i] * a[high]);
    }

    return dp[low][high];
}

int main(){

    // for(int  i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //       dp[i][j] = -1;
    //     }
      
    // }

    int n ;
    cin >> n;
    vector<int> a(n);



    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i =0 ; i < n; i++){
        dp[i][i] = 0;
    }

    for(int l = 2; l < n; l++){
        for(int i = 1; i <n -l +1; i++){
             int j = i + l -1;
             dp[i][j] = MODE;
             for(int k = i; k < j; k++){
                dp[i][j] =  min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j]);
             }
        }

    }
    
    cout << dp[1][n-1] << endl;
}