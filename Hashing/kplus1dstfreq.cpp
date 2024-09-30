#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    map<int, int> freq;

    for(int i = 0; i < n; i++){    
        if(freq.size() == k+1 && freq[v[i]] == 0)   
          break; 
        freq[v[i]]++;
    }

    map<int, int> :: iterator it;

    for(it  = freq.begin(); it != freq.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;

}