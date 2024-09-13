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

int maxSumUtily(Node *root, int &ans){
    if(root == NULL) return 0;
    int left = maxSumUtily(root->left, ans);
    int right = maxSumUtily(root->right, ans);
    int nodeMax = max(max(root->data, root->data +left+ right), 
                  max(root->data+left, root->data + right));
    ans = max(ans, nodeMax);
    int singlePath = max(root->data,max(root->data + left, root->data + right));
    return singlePath;
}

int maxSum(Node *root){
    int ans = INT_MIN;
    maxSumUtily(root, ans);

    return ans;
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

    cout << maxSum(root)  << endl;
        
    return 0;
}