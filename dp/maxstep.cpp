#include<bits/stdc++.h>
using namespace std;
const int INF = 1e3+2;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
   
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    if(arr[0] == 0){
        cout << INF << endl;
        return 0;
    }
    vector<int> dp(n, INF);

    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(i <= j + arr[j]){
                dp[i] = min(dp[i], 1+dp[j]);
            }
        }
    }

    cout <<  dp[n-1] << endl;

    return 0;
}