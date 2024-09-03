#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; 
    cin >> n >> k;
    vector<int> v(n);
    for(auto & i : v){
        cin >> i;
        
    }
    // 0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1 

    

    int ans = 0, i =0, j; 
    int zerocount = 0;

    for(j = 0; j < n; j++){
        if(v[j] == 0)
           zerocount++;

        while(zerocount > k){
            if(v[i] == 0){
                zerocount--;
            }
            i++;
        }

        ans = max(ans, j - i +1);
    }  

    cout << ans << endl;

    return 0;
}