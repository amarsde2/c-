#include<bits/stdc++.h>
using namespace std;
const int N  = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);

void make_parent(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(v == parent[v]) 
       return v;
    return parent[v] = find_set(parent[v]);
}


bool unionSet(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
       if(sz[a] < sz[b]){
          swap(sz[a],sz[b]);
       }
       parent[b] = a;
       sz[a] += sz[b];
       return true;
    } 
    return false;
}

int main(){
    int m; 
    cin >> m;

    for(int i = 0; i < N; i++){
        make_parent(i);
    }
    vector<vector<int>> edges;
    bool isCycle = false;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    for(int i = 0; i < m; i++){
       int u = edges[i][0];
       int v = edges[i][1];
       if(!unionSet(u, v)){
         isCycle = true;
       }
    }

    if(isCycle) {
        cout << "Cycle found: " << endl;
    } else{
        cout << "Cycle not found: " << endl;
    }

    return 0 ;
}