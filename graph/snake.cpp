#include<bits/stdc++.h>
using namespace std;

int main(){
    int landers, snakers; 
    cin >> landers >> snakers;
    map<int, int> lands;
    map<int, int> snak;

    for(int i = 0; i < landers; i++){
        int u, v;
        cin >> u >> v;
        lands[u] = v;
    }

    for(int i = 0; i < snakers; i++){
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }

    vector<bool> visited(101, 0);
    bool found = false;
    int step = 0;
    queue<int> q;
    q.push(1);

    visited[1] = true;

    while(!q.empty() && !found){
        int sz = q.size();

        while(sz--){
            int t = q.front();
            q.pop();
        
            for(int dict = 1; dict <= 6; dict++){
                if(t + dict == 100){
                    found = true;
                }

                if(t + dict <= 100  && lands[t + dict] && !visited[t+dict]){

                    visited[t+dict] = true;
                    if(lands[t + dict] == 100){
                        found = true;
                    }
                    q.push(lands[t+ dict]);
                }
                else if(t + dict <= 100  && snak[t + dict] && !visited[t+dict]){
                   
                    visited[t+dict] = true;
                    if(snak[t + dict] == 100){
                        found = true;
                    }
                    q.push(snak[t+ dict]);
                } else{
                    visited[t+dict] =true;
                    q.push(t+dict);
                }
            }
        }
        
        step++;
    }
    
    if(found){
        cout << step << endl;
    } else{
        cout << "-1" << endl;
    }
   
    return 0;
}