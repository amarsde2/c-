#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int i = 1;
    int v = 1;
    int mask =  ~(1 << i);
    n = n & mask;
    n = n |  (v  << i);

    cout << "n = " << n << endl;
    return 0;
}

