#include<bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   struct Node* left, *right;
};


Node *newNode(int data){
    struct Node *temp = new Node; 
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


void getHorizentailTraversal(Node *root, int hi, map<int, vector<int>> &pm){
    if(root == NULL) return;
    pm[hi].push_back(root->data);

    getHorizentailTraversal(root->left, hi-1, pm);
    getHorizentailTraversal(root->right, hi+1, pm);
}

int main(){
    struct Node *root = newNode(10);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(6);
    root->left->right = newNode(7);
    root->right->left = newNode(8);
    root->right->right = newNode(9);
    
    map<int, vector<int>> pm;
    int hi = 0;
   
    getHorizentailTraversal(root, hi, pm);
   
    map<int, vector<int>> ::iterator  it;

    for(it = pm.begin(); it != pm.end(); it++){
        
        for(int i = 0; i < (it->second).size(); i++){
            cout << (it->second)[i] << " ";
        }

        cout<< endl;
    }

    return 0;

}