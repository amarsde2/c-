#include<bits/stdc++.h>
using namespace std;

int getTitlingWay(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return getTitlingWay(n-1) + getTitlingWay(n-2);
}

int main(){
    int n = 6;
    
    cout << getTitlingWay(n) << endl;

    return 0;
}