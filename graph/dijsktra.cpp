#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<int> distance(n+1, INT_MAX);

    int source;
    cin >> source;

    distance[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});

    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        int ne = x.second;
        for(auto it: graph[ne]){
            if(distance[it.first] > distance[x.second] + it.second){
              s.erase({distance[it.first], it.first});
              distance[it.first] = distance[x.second] + it.second;
              s.insert({distance[it.first], it.first});
            }
        }
    }

    for(int i = 1; i < n; i++){
        if(distance[i] < INT_MAX){
            cout << distance[i] << " ";
        } else{
            cout << "-1";
        }
    }


    return 0;
}


