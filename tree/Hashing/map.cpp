#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
       cin >> v[i];
    }

    map<int, int> pm;

    for(int i = 0; i < n; i++){
        pm[v[i]]++;
    }

    map<int, int> ::iterator it;

    for(it = pm.begin(); it != pm.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
    
}