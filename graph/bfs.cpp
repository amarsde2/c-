#include<bits/stdc++.h>
using namespace std;

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
    
    int visited[n+1] = {0};
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int v = q.front();
        cout << v << endl;
        q.pop();
        for(int i = 0; i < a[v].size() ; i++){
            if(!visited[a[v][i]]){
                visited[a[v][i]] = true;
                q.push(a[v][i]);
            }
        }
    }

    return 0;
}
