#include<bits/stdc++.h>
using namespace std;
#define int long long

/**
 * Function to compute (x^y) % p using modular exponentiation
 */
int power(int x, int y, int p){
    int res = 1;
    x = x % p;  // Update x if it is more than or equal to p
    while(y > 0){
        // If y is odd, multiply x with the result
        if(y & 1){
            res = (res * x) % p;
        }
        // y must be even now
        x = (x * x) % p;  // Change x to x^2
        y = y >> 1;  // Divide y by 2
    }
    return res;
}

/**
 * Function to find modular inverse of a under modulo p
 * using Fermat's Little Theorem. p must be prime.
 */
int moduleInverse(int a, int p){
    return power(a, p - 2, p);
}

/**
 * Function to compute the "boring" factorial as per the problem's description
 */
int foundBoringFac(int n, int p){
    // If p is less than or equal to n, factorial mod p is 0
    if(p <= n) return 0;

    // Initialize result as p-1 (as per the logic)
    int ans = p - 1;

    // Compute the factorial from n+1 to p-1 and find modular inverse
    for(int i = n + 1; i < p; i++){
        ans = (ans * moduleInverse(i, p)) % p;
    }

    return ans;
}

signed main(){
    int n, p;
    cin >> n >> p;
    cout << foundBoringFac(n, p) << endl;
    return 0;
}
