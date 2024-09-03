#include<bits/stdc++.h>
using namespace std;


int main(){
    multiset<int, greater<int>> s;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> ans;

    for(auto &i : v){
        cin >> i;
    }

    for(int i = 0; i < k; i++){
        s.insert(v[i]);
    }

    ans.push_back(*s.begin());

    for(int i = k; i < n; i++){
        s.erase(s.lower_bound(v[i-k]));
        s.insert(v[i]);
        ans.push_back(*s.begin());
    }

    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;

}