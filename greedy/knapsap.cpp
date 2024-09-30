#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n ;
    
    vector<pair<int, int>> a;
    
    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        a.push_back({start, end});
    }

    sort(a.begin(), a.end(),[&](pair<int, int> a, pair<int,int> b){
        return  (double)a.first / a.second > (double)b.first/b.second;
    });
  
    int w;

    cin >> w;
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(w >= a[i].second){
            ans += a[i].first;
            w -= a[i].second;
            continue;
        }

        double wv = (double) a[i].first / a[i].second;
        ans += wv * w;
        w = 0;
        break;
    }

    cout << ans << endl;

    return 0;
}