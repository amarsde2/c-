#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; 
    cin >> n;
    vector<int> a(n);
    vector<vector<int>>ans;
    for(auto &i: a){
        cin >> i;
    }
    
    do{
        ans.push_back(a);
    }while(next_permutation(a.begin(), a.end()));

    for(auto v : ans){
       for(auto i : v){
          cout << i << " ";
       }
       cout << endl;
    }

    return 0;
}