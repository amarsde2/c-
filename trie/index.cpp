#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    class Node{
        public:
        bool end;
        Node *next[26];
        Node(){
          end = false;
          for(int i=0; i<26; i++){
            next[i] = NULL;
          }
        }
    };
    Node *trie;
    Trie(){
        trie = new Node();
    }

    void insert(string word){
        int i = 0;
        Node *it = trie;
        while(i < word.size()){
            if(it->next[word[i] - 'a'] == NULL){
                it->next[word[i] - 'a'] = new Node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }

    bool search(string word){
        int i = 0;
        Node *it = trie;
        while(i < word.size()){
            if(it->next[word[i] - 'a'] == NULL){
                return false;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};


int main(){
    Trie  *mytree = new Trie();

    mytree->insert("hello");
    mytree->insert("world");

    if(mytree->search("hello")){
        cout << "word found " << endl;
    }
    if(mytree->search("world")){
        cout << "word found " << endl;
    }

    return 0;
}