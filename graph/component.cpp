#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> dist;
vector<bool> visited;
vector<int> component_count;

int getComponent(int i){
    if(visited[i]) return 0;
    visited[i] = true;
    int ans = 1;
    for(auto j : dist[i]){
       if(!visited[j]){
        ans += getComponent(j);
        visited[j] = true;
       }
    }
    return ans;
}

int main(){ 
   
    cin >> n >> m ;
    dist = vector<vector<int>>(n);
    visited = vector<bool>(n);
    for(int i = 0; i < m; i++){
        int b, c;
        cin >> b >> c;
        dist[b].push_back(c);
        dist[c].push_back(b);
    }
   
    for(int i = 0; i < n; i++){
        if(!visited[i])
           component_count.push_back(getComponent(i));
    }

    for(auto i : component_count){
       cout << i << " ";
    }

    long long totalway = 0;
 
    for(auto i : component_count){
      totalway += i * (n-i);
    }

    cout << totalway/2 << endl;


    return 0;
}
