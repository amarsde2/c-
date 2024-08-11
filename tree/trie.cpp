#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class TrieNode{
      public: 
      unordered_map<char, TrieNode*> children;
      bool isEndOfWord; 
  
      TrieNode(){
        isEndOfWord = false;
      }
};



class Tree{
    TrieNode *root;
    public: 
    Tree(){
        root = new TrieNode();
    }

    void insert(string words){
        
        TrieNode *curr = root;
        for(char ch: words){
           if(curr->children.find(ch)  == curr->children.end()){
               curr->children[ch] = new TrieNode();
           }

           curr = curr->children[ch];
        }
        curr->isEndOfWord = true;
    }

    void printWords(TrieNode *node, string prefix){
        if(node->isEndOfWord){
            cout << prefix << endl;
        }
  
        for(auto entry: node->children){
            printWords(entry.second, entry.first + prefix);
        }
    }

    bool deleteHelper(TrieNode *node, string word, int index){
        if(index == word.length()){
            if(!node->isEndOfWord){
                return false;
            }
            node->isEndOfWord = false;
            return node->children.empty();
        }

        char ch = word[index];

        if(node->children.find(ch) ==  node->children.end()){
            return false;
        }

        TrieNode *child = node->children[ch];

        bool isFound = deleteHelper(child, word, index+1);

        if(isFound){
            node->children.erase(ch);
            return node->children.empty();
        }

        return false;

    }

    bool deleteWord(string word){

         return deleteHelper(root, word, 0);
    }

    bool startsWith(string word){
        TrieNode *curr = root;
        for(char ch : word){
            if(curr->children.find(ch) == curr->children.end()){
                return false;
            }
            curr = curr->children[ch];
        }

        return true;
    }

    bool search(string words){
        TrieNode *curr = root;
        
        for(char ch: words){
            if(curr->children.find(ch) == curr->children.end()){
                return false;
            } 
            curr = curr->children[ch];
        }
        return true;
    }

    TrieNode * getRoot(){
        return root;
    }
};


int main(){
    Tree car;
    car.insert("Lamborghini");
    car.insert("Mercedes-Benz");
    car.insert("Land Rover");
    car.insert("Maruti Suzuki");
    //Before Deletion
    cout <<"Tries elements before deletion: \n";
    car.printWords(car.getRoot(), "");
    //Deleting elements using deletion operation
    string s1 = "Lamborghini";
    string s2 = "Land Rover";
    cout<<"Elements to be deleted are: \n"<<s1<<" and "<<s2;
    car.deleteWord("Lamborghini");
    car.deleteWord("Land Rover");
    //After Deletion
    cout << "\nTries elements after deletion: \n";
    car.printWords(car.getRoot(), "");

    return 0;
}



