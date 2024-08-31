#include<bits/stdc++.h>
using namespace std;

int pairWay(int n ){

    if(n == 0 || n == 1 || n == 2){
        return n;
    }

    return pairWay(n-1) + pairWay(n-1)*pairWay(n-2);
}

int main(){
    int n = 5;
    cout << pairWay(n) << endl;
    return 0;
}