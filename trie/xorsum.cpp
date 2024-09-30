#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* next[2];
    TrieNode(){
        next[0] = NULL;
        next[1] = NULL;
    }
};

TrieNode * buildTrie(vector<int> &a){
    TrieNode *root = new TrieNode();

    for(int i = 0; i < a.size(); i++){
        int num = a[i];
        TrieNode *curr = root;
        for(int j = 31; j >= 0; j--){
            int bit = num >> j & 1;
            if(curr->next[bit] == NULL){
                curr->next[bit] = new TrieNode();
            }
            curr = curr->next[bit];
        }
    }

    return root;
}

int calculate(TrieNode *root, vector<int> &a){
    int res = 0;

    for(int i = 0; i < a.size(); i++){
        int num = a[i];
        TrieNode *curr = root;
        int curr_max = 0;
        for(int j = 31; j >= 0; j--){
            int bit = (num >> j) & 1;
            if(curr->next[1 -bit]){
               curr_max = (curr_max << 1) | 1;
                curr =  curr->next[1-bit];
            } else{
                curr_max = curr_max << 1;
                 curr =  curr->next[bit];
            }
           
        }
        res = max(res, curr_max);
    }
    return res;
}

int main() {
    vector<int> a = {3, 10, 5, 15, 2};
    TrieNode *root = buildTrie(a);

    int ans = calculate(root, a);

    cout << ans << endl;
}
