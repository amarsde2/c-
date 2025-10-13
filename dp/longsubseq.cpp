#include<bits/stdc++.h>
using namespace std;


int findLong(string s1, string s2, int m, int n){
    
    if(m == 0 || n == 0) return 0;

    if(s1[m-1] == s2[n-1]){
        return 1 + findLong(s1, s2, m-1, n-1);
    } else{
        return max(findLong(s1, s2, m, n-1), findLong(s1, s2, m-1, n));
    }
}


int main(){
    string s1 = "hello";
    string s2 = "ieu";
    
    cout << findLong(s1, s2, s1.size(), s2.size()) << endl;

    return 0;
}