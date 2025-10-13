#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> memo;

int findWayToTrue(string& s, int i, int j, bool match){
    if( i > j) return false;
    
    string key  = to_string(i) + "_" + to_string(j)  + "_"+ to_string(match);

    if(memo.find(key) != memo.end()) return memo[key];

    if(i == j){
        if(match == true){
            return s[i] == 'T';
        } else{
            return s[i] == 'F';
        }
    }
    
    int ans = 0;

    for(int k = i + 1; k < j; k += 2){
        int lt = findWayToTrue(s, i, k-1, true);
        int lf = findWayToTrue(s,i , k-1, false);
        int rt = findWayToTrue(s,k+1, j, true);
        int rf=  findWayToTrue(s, k+1 ,j, false);

        if(s[k] == '&'){
            if(match == true){
                ans += lt * rt;
            } else{
                ans += lt * rf + rt * lf + lf* rf;
            }
        } else if(s[k] == '|'){
            if(match == true){
                ans += lt* rt + lt*rf + rt *lf;
            } else{
                ans += lf*rf;
            }
        } else if(s[k] == '^'){
            if(match == true){
                ans += lt*rf  + rt * lf;
            } else{
                ans += lf*rf + lt * rt;
            }
        }
    }
    
    return memo[key] = ans;
}

int main(){
    string  s = "T&F^T";
    bool match = true;
    int ans = findWayToTrue(s, 0, s.size()-1, match);
    cout << ans << endl;

    return 0;
}