#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int main(){
    int k;
    cin >> k;
    vector<vector<int>>a(k);

    for(int i=0; i<k; i++){
        int size;
        cin >> size;
        a[i] = vector<int>(size);
        for(int j = 0; j < size; j++){
            cin >> a[i][j];
        }
    }

    vector<int> idx(k,0);
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    for(int i = 0; i < k; i++){
        if(a[i].size() > 0)
          pq.push({a[i][0] ,i});
    }

    vector<int> ans;


    while(!pq.empty()){
       pi x = pq.top();
       pq.pop();
       ans.push_back(x.first);

       if(idx[x.second] + 1 < a[x.second].size()){
          idx[x.second]++;
          pq.push({a[x.second][idx[x.second]], x.second});
       }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}