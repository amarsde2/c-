#include<bits/stdc++.h>
using namespace std;

double getPow(double x, int n){
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == -1 && n % 2 == 0) return 1.0;
    if(x == -1 && n % 2 != 0) return -1.0;
    if(n < 0){
        n = -n;
        x = 1/x;
    }
    double ans = 1;
    while(n > 0){
        if(n % 2 == 1){
            ans *= x;
        }
        x = x*x;
        n /= 2;
    }

    return ans;
}

int main(){
    double x;
    int n;
    cin >> x >> n;

    cout << getPow(x,n)<< endl;
}