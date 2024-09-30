#include<bits/stdc++.h>
using namespace std;
vector<int> bits;

int getSum(int n){
    int ans = 0;
    while(n > 0){
        ans += bits[n];  // Fixed: use += to accumulate the sum
        n -= n & (-n);
    }
    return ans;
}

void update(int n, int i, int val){
    while(i <= n){
        bits[i] += val;  // Fixed: use += to update the BIT
        i += i & (-i);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> temp(n);
    
    // Input array
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    // Sort and compress the array
    temp = a;
    sort(temp.begin(), temp.end());
    bits = vector<int>(n+1, 0);  // Initialize BIT

    for(int i = 0; i < n; i++){
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
    }

    int countInv = 0;

    // Count inversions
    for(int i = n-1; i >= 0; i--){
        countInv += getSum(a[i]);  // Count smaller elements
        update(n, a[i]+1, 1);      // Update the BIT for the current element
    }

    // Output the inversion count
    cout << countInv << endl;

    return 0;
}
