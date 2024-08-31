#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5; // 101 
    int i = 2; // 011
            
    cout << (n & (~(1 << i))) << " " << endl;
    return 0;
}