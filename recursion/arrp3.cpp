#include<bits/stdc++.h>
using namespace std;



void generatePerm(vector<int> &a, vector<vector<int>> &ans, int idx){
    
    if(idx == a.size()){
        ans.push_back(a);
    }

    for(int i = idx ; i < a.size() ; i++){
        if(i != idx && a[i] == a[idx]) 
          continue;
        swap(a[i], a[idx]);
        generatePerm(a, ans, idx+1);
        swap(a[i], a[idx]);
    } 
}

int main(){
    int n; 
    cin >> n;
    vector<int> a(n);

    vector<vector<int>>ans;
    for(auto &i: a){
        cin >> i;
    }

    sort(a.begin(), a.end());

    generatePerm(a, ans, 0);

    for(auto v : ans){
       for(auto i : v){
          cout << i << " ";
       }
       cout << endl;
    }

    return 0;
}