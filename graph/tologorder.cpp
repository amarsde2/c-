#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> adj(n+1);
    vector<int> in_order(n,0);
    
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_order[v]++;
    }

    queue<int> qu;

    for(int i = 0; i < n; i++){
        if(in_order[i] == 0){
            qu.push(i);
        }
    }
     
    while(!qu.empty()){
       int top = qu.front();
       qu.pop();
       cout << top << endl;

       for(int i = 0; i < adj[top].size(); i++){
          in_order[adj[top][i]]--;
          if(in_order[adj[top][i]] == 0){
            qu.push(adj[top][i]);
          }
       }
    }

    return 0;
}