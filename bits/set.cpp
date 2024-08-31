#include<bits/stdc++.h>
using namespace std;

void setBit(int n, int pos){
    n = n  | ( 1 << pos);
    cout << n  << endl;
}


int main(){
    int n = 5;
    int pos = 1;
    
    setBit(n,pos);

    cout << "Bit set";
}