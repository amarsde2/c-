#include<bits/stdc++.h>
using namespace std;

void solve(int n, char source, char target, char via){

    if( n == 1 ){
        cout << "Move disk from " << source << " -> "  << target << endl;
    } else{
        solve(n-1, source, via, target);
        cout << "Move disk from " << source << " -> "  << target << endl;
        solve(n-1, via, target, source);
    }
}

int main(){
    int n = 5;
    char from = 'A';
    char to = 'C';
    char via = 'B';


    solve(n, from , to  , via);

    return 0;
}