#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int> v(k);
    for(int i=0; i<k; i++){
        cin >> v[i];
    }

    map<int, int> cm;
    int ans = 0;
    int presum = 0;

    for(int i=0; i<k; i++){
       presum += v[i];
       cm[presum]++;
    }

    map<int, int> ::iterator it;

    for(it=cm.begin(); it!=cm.end(); it++){
        int ct = it->second;
        ans += ct * (ct-1)/2;
        if(it->first == 0){
            ans += it->second;
        }
    }

    cout << ans << endl;

    return 0;
}