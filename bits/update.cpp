#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int i = 1;
    int mask =  ~(1 << i);
    int na = n & mask;
    cout << (n | (1 << i) ) << endl;
    return 0;
}