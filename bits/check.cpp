#include<bits/stdc++.h>
using namespace std;

int main(){
   
    int n = 5; // 101
    int i = 1; //  10

    if( (n & (1 << i)) != 0){
        cout << "Find 1's in string " << endl;
    } else{
        cout << "Not found" << endl;
    }

    return 0;
}