#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);

    cout << (c1 + c2 - c3) << endl;

    return 0;

}