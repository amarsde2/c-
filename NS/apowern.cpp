#include<bits/stdc++.h>
using namespace std;

const int MODULE = 1e9+7;


/**
 * 
 * @Recursive function  
*/

long long getPower(long long a, long long n){
    if(n == 0) return 1;

    long long p = (getPower(a, n/2)) % MODULE;
    if(n & 1){
        return (((p*p) % MODULE)* a) % MODULE;
    } else{
        return (p*p) % MODULE;
    }
}

long long power(long long a, long long n) {
    a = a % MODULE;
    long long ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % MODULE;
        }
        a = (a * a) % MODULE;
        n = n >> 1;
    }
    return ans;
}

int main() {
    long long a, n;
    cin >> a >> n;
    a = a % MODULE;
    cout << getPower(a, n) << endl;

    return 0;
}
