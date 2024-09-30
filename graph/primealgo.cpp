#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
const int INF = 99999;
int n, m;
vector<int> parent(N);
vector<int> sz(N);
vector<bool> visited(N,false);
vector<int> dist(N);
vector<pair<int, int>> grph[N];
int cost  = 0;

void make_parent(int v){
     parent[v] = v;
     sz[v] = 1;
}


void prime(int source){
    for(int i = 0; i < n; i++){
        dist[i] = INF;
    }
    
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});

    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        int u = x.second;
        int w = x.first;
        if(visited[u]) 
           continue;
        visited[u] = true;
        cost += w;
        cout << u << " " << parent[u] << " " << w << endl;

        for(auto it: grph[u]){
            if(visited[it.first]) 
               continue;

            int negibor = it.first;
            int weight = it.second;

            if(!visited[negibor] && dist[negibor] > weight){
               s.erase({dist[negibor], negibor});
               dist[negibor] = weight;
               s.insert({dist[negibor], negibor});
               parent[negibor] = u;
            }
       }
    }
    cout << cost << endl;
    return;
}
 

int main(){
    
    cin >> n >> m;

    for(int i =0 ; i < n; i++){
        make_parent(i);
    }

    for(int i = 0; i < m; i++){
        int u, v , w;
        cin >> u >> v >> w;
        grph[u].push_back({v,w});
        grph[v].push_back({u,w});
    }

    prime(0);

    return 0;
}