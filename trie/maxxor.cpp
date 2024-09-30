#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *next[2];
    Node(){
    for(int i = 0; i < 2; i++)
    {  
        next[i] = NULL;
    }
    }
};

Node *root;

void insert(int n){
    Node *it = root;
    for(int i = 31; i >= 0 ; i--){
        int cb = (n >> i) & 1;
        if(it->next[cb] == NULL){
           it->next[cb] = new Node();
        }
        it = it->next[cb];
    }
}
int query(int n){
    int ans = 0;
    Node *it = root;
    for(int i = 31; i >= 0; i--){
        int cb = (n >> i) & 1;
        if(it->next[cb ^ 1]){
            ans |= (1 << i);
            it = it->next[cb ^ 1];
        } else {
            it = it->next[cb];
        }
    }   
    return ans;
}


int main(){
    root = new Node();
    int n; 
    cin >>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> rmax(n+1,0);

    insert(0);

    int r = 0;

    for(int i = n-1; i >= 0; i--){
       r  = r ^ v[i];
       rmax[i] = max(rmax[i+1], query(r));
       insert(r);
    }

    free(root);

    root = new Node();

    insert(0);
    int l = 0;
    int ans = 0;

    for(int i = 0; i < n-1; i++){
        l = l ^ v[i];
        ans  = max(ans, rmax[i+1] + query(l));
        insert(l);
    }

    cout << ans << endl;

    free(root);
    
    return 0;
}