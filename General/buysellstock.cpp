#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int bestBuy = arr[0];
    int profit = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] <= bestBuy){
           bestBuy = min(bestBuy, arr[i]);
        } else{
           profit = max(profit, arr[i] - bestBuy);
        }
    }

    cout <<  profit << endl;
    
    return 0;
}