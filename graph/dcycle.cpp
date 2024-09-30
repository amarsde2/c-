#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &a, vector<bool> &visited, int src,  vector<int> &st){
    st[src] = true; 

    if(!visited[src]){
        visited[src] = true;
        for(auto i: a[src]){
            if(!visited[i] && isCycle(a, visited, i, st)){
                return true;
            }
            if(st[i]){
                return true;
            }
        }
    }
   
    st[src] = false;
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
    }
    bool cycle = false;
    vector<int> st(n,0);
    vector<bool> visited(n, 0);

    for(int i = 0 ; i < n; i++){
        if(!visited[i] && isCycle(a, visited, i, st)){
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
