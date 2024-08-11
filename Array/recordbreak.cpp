#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n+1];
    arr[n] = -1;

    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }

    int maxN = -1;
    int ans = 0 ;
    for(int i = 0 ; i < n; i++){
        
        if(arr[i] > maxN && arr[i] > arr[i+1]){
           ans++;
        }

        maxN = max(maxN, arr[i]);
    }

    cout << ans << endl;

    return 0;
}