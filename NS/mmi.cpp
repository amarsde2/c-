#include<bits/stdc++.h>
using namespace std;

struct triplet {
   int x, y, gcd;
}; 

triplet advanceEuclidean(int a, int b){
    if(b == 0){
        triplet ans;
        ans.x  = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet small = advanceEuclidean(b, a % b);
    triplet ans;
    ans.x = small.y;
    ans.y = small.x - (a/b)* small.y;
    ans.gcd = small.gcd;

    return ans;
}


int findMultipleModuleInverse(int a, int m){
    triplet ans = advanceEuclidean(a, m);
    return ans.x;
}

int main(){
    int a, m;

    cin >> a >> m;

    cout << findMultipleModuleInverse(a, m) << endl;
}