#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &a, vector<bool> &visited, int src, int parent){
   
    visited[src] = true;
    
    for(auto i: a[src]){
        if(i != parent){
            if(visited[i] == true)
               return true;

            if(!visited[i] && isCycle(a, visited, i, src)){
                return true;
            } 
        }
    }
    return false;

}

int main(){ 
    int n,m;
    cin >> n >> m;
    
    // Use a dynamic vector of vectors instead of a fixed-size array
    vector<vector<int>> a(n);  // Dynamically size it based on 'n'

    for(int i = 0; i < m; i++){
        int b, c;
        cin >> b >> c;
    
        a[b].push_back(c);
        a[c].push_back(b);
    }
    bool cycle = false;
    vector<bool> visited(n, false);

    for(int i = 0 ; i < n; i++){
        if(!visited[i] && isCycle(a, visited, i, -1)){
           cycle = true;
        }
    }

    if(cycle){
        cout << "Cycle found";
    } else{
        cout << "Not found  ";
    }

    return 0;
}
