#include<bits/stdc++.h>
using namespace std;
#define N 7

int visited[N] = {0};


void dfs(vector<vector<int>> a, int node){
    visited[node] = true;
    cout << node << endl;

    for(int i = 0; i < a[node].size(); i++){
        if(!visited[a[node][i]]){
            dfs(a, a[node][i]);
        }
    }   

    return;
}

int main(){ 
    int n;
    cin >> n;
    
    // Use a dynamic vector of vectors instead of a fixed-size array
    vector<vector<int>> a(n+1);  // Dynamically size it based on 'n'

    for(int i = 0; i < n; i++){
        int b, c;
        cin >> b >> c;
        
        // Adjust the size of vector 'a' based on max value of b and c
        if(max(b, c) >= a.size()) {
            a.resize(max(b, c) + 1);
        }

        a[b].push_back(c);
        a[c].push_back(b);
    }

    dfs(a,1);
     
    return 0;
}
