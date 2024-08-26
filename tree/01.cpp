#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int knapSack(int W, int wi[], int val[], int n){
    vector<vector<int>> K(n+1, vector<int>(W+1));
    int i , w;
    for(i = 0; i <= n; i++){
        for(w = 0 ; w <= W; w++){
            if(i == 0 || w == 0){
                K[i][w] = 0;
            } else if( wi[i-1] <= w){
                K[i][w] = max(val[i-1] + K[i-1][w-wi[i-1]] , K[i-1][w]);
            } else{
                K[i][w] = K[i-1][w];
            }
        }
    }

    return K[n][W];
}


int main(){
    int val[] = { 70, 20, 50 };
    int wt[] = { 11, 12, 13 };
    int W = 30;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "Maximum Profit achieved with this knapsack: " << knapSack(W, wt, val, n);
    return 0;
}