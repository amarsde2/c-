#include<bits/stdc++.h>
using namespace std;
struct elc {
   int x;
   int y;
   int gcd;
};


elc calculateElc(int a, int b){
    
    if(b == 0){
        elc ans;
        ans.gcd  = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    
    elc small = calculateElc(b, a%b);
    
    elc ans;

    ans.gcd = small.gcd;
    ans.x = small.y;
    ans.y = small.x - (a/b)*small.y;

    return ans;
}



signed main(){
    int a, b;
    cin >> a >> b;

    elc c = calculateElc(a,b);
     
    cout << c.x << " " << c.y << " " << c.gcd << endl;

    return 0;

}

