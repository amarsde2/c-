#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node *left, *right;
   Node(int val){
    data = val;
    left = right = NULL;
   }
};


// code to print possible bst from given number of nodes



vector<Node*> generatePossiableTree(int start, int end){
    vector<Node*> trees;
    
    if(start > end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i = start; i <= end; i++){
        vector<Node*> leftSubtree = generatePossiableTree(start,i-1);
        vector<Node*> rightSubtree = generatePossiableTree(i+1, end);
        
        for(int j = 0; j < leftSubtree.size(); j++){
            Node* leftN = leftSubtree[j];
            for(int k = 0; k < rightSubtree.size(); k++){
                Node* rightN = rightSubtree[k];
                Node *root = new Node(i);
                root->left = leftN;
                root->right = rightN;
                trees.push_back(root);
            }
        }
    }

    return trees;
}

void displayTree(Node *root){
    if(root != NULL){
      cout << root->data << " ";
      displayTree(root->left);
      displayTree(root->right);
    }
    
}


int main(){
    vector<Node *> trees= generatePossiableTree(1, 3);
    
    for(int i = 0; i < trees.size(); i++){
        displayTree(trees[i]);
        cout << endl;
    }

    return 0;

}