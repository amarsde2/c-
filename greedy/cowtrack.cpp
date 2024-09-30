#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
 
    while(t--){ 
        int n;
        cin >> n;
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; i++){
           cin >> a[i].first >> a[i].second;
        }
        int l,p;
        cin >> l >> p;
        // update distance from destination
        for(int i = 0; i < n; i++){
           a[i].first = l - a[i].first;
        }

        sort(a.begin(), a.end());
        priority_queue<int, vector<int>> q;
        int curr = p;
        int ans = 0;
        bool flag = 0;
        for(int i = 0 ; i < n; i++){
            if(curr >= l){
                break;
            }
           
            while(curr < a[i].first){
                if(q.empty()){
                    flag = 1;
                    break;
                }
                curr += q.top();
                q.pop();
                ans++;
            }
            if(flag){
                break;
            }
            q.push(a[i].second);
        }
        
        if(flag){
            cout << "-1" << endl;
            continue;  
        }

        while(!q.empty() && curr < l){
            curr += q.top();
            q.pop();
            ans++;
        }

        if(curr < l){
            cout << "-1" << endl;
            continue;
        }
      
        cout <<  ans << endl;
    }
    return 0;
}