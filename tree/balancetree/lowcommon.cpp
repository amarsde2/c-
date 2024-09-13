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

bool getPath(Node *root, int n, vector<int> &path){
    if(root == NULL) return false;
    path.push_back(root->data);

    if(root->data == n) return true;

    if(getPath(root->left, n, path) || getPath(root->right, n, path)){
       return true;
    }

    path.pop_back();
    
    return false;
}

int getLowestCommentAncestor(Node *root, int n1, int n2){
    vector<int> path1;
    vector<int> path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int ps;

    for(ps = 0; ps < path1.size() && path2.size(); ps++){
        if(path1[ps] != path2[ps]){
           break;
        }
    }
    return path1[ps-1];
}

Node *findLCS(Node *root, int n1, int n2){
   if(root == NULL) return NULL;
   if(root->data == n1 || root->data == n2) return root;
   
   Node *left = findLCS(root->left, n1, n2);
   Node *right = findLCS(root->right, n1, n2);

   if(left != NULL && right != NULL) return root;

   if(left != NULL) return left;

   return right;

}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->right->left = new Node(10);
   
    // Approach first for finding lowest comment ancestor of two nodes

    // if(getLowestCommentAncestor(root,4 ,5 ) == -1){
    //     cout << "WARNING Solution Does not exist!" << endl;
    // } else{
    //     cout << getLowestCommentAncestor(root,4,5 ) << endl;
    // }

    // improved approach 

    Node *lcs = findLCS(root , 4,5);
    if(lcs){
        cout << lcs->data << endl;
    } else{
        cout << "ERROR Solution does not exist!" << endl;
    }
    
    return 0;
}