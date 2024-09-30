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

    for(int i = 1; i < a.size(); i++){
        cout << i << " -> ";
        for(int j: a[i]){
           cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
