#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n];
    int csum[n+1];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    csum[0]  = 0;
    
    for(int i=1; i<=n; i++){
        csum[i] = csum[i-1] + arr[i-1];
    }

    int maxSum = INT_MIN;

    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 0; j < i; j++){
            sum = csum[i] - csum[j];
            maxSum = max(maxSum, sum);
        }
    }
   
    cout << maxSum << endl;

    return 0;
}