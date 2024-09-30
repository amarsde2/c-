#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
       cin >> a[i];
    }

    long long maxDiff = 0, minDiff = 0;

    sort(a.begin(), a.end());
    
    // Calculate max difference
    for(int i = 0; i < n/2; i++){
        maxDiff += a[n-i-1] - a[i];
    }
    
    // Calculate min difference
    for(int i = 1; i < n; i += 2){
        minDiff += a[i] - a[i-1];
    }

    cout << maxDiff << " " << minDiff << endl;

    return 0;
}
