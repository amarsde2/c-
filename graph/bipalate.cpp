#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> dist;
vector<bool> visited;
vector<int> colr;
bool bilpalatre = true;  // Initially assume graph is bipartite

void color(int v, int co){
    if(colr[v] != -1 && colr[v] != co){
        bilpalatre = false;  // Not bipartite if colors don't match
        return;
    }
    colr[v] = co;
    if(visited[v]) return;
    visited[v] = true;
    for(auto i : dist[v]){
        color(i, co ^ 1);  // Toggle color for the neighbor
    }
}

int main(){ 
    cin >> n >> m;
    dist = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    colr = vector<int>(n, -1);
   
    for(int i = 0; i < m; i++){
        int b, c;
        cin >> b >> c;
        dist[b].push_back(c);
        dist[c].push_back(b);
    }
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            color(i, 0);  // Start coloring with 0
        }
    }   
    
    if(bilpalatre){
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not bipartite" << endl;
    }

    return 0;
}
