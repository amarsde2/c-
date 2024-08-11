#include<bits/stdc++.h>
using namespace std;

struct Node{
   int data, color;
   struct Node *parent, *left, *right;
};

typedef Node *Nodeptr;

class Rbtree{
private:
 Nodeptr root, tnull;

void rightRotate(Nodeptr x){
    Nodeptr y = x->left;
    x->left = y->right;
    
    if(y->right != tnull){
        y->right->parent = x;
    }
    
    y->parent = x->parent;

    if(x->parent == nullptr){
        root = y;
    } else if(x == x->parent->left){
        x->parent->left = y;
    } else if(x == x->parent->right){
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

void leftRotate(Nodeptr x){
    Nodeptr y = x->right;
    x->right = y->left;
    
    if(y->left != tnull){
        y->left->parent = x;
    }
    
    y->parent = x->parent;

    if(x->parent == nullptr){
        root = y;
    } else if(x == x->parent->left){
        x->parent->left = y;
    } else if(x == x->parent->right){
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void printHelper(Nodeptr root, string indent, bool last){
    if(root != tnull){
        cout << indent;
        if(last){
            cout << "R ---";
            indent += " ";
        } else{
            cout << "L---";
            indent += "| ";
        }
        string Color = root->color ? "Red" : "Black";

        cout << root->data << " (" << Color << " )" << endl;
        printHelper(root->left, indent, false);
        printHelper(root->right, indent, true);
    }
}

void insertFix(Nodeptr k){
    Nodeptr s;

    while(k->parent->color  == 1){
        if(k->parent == k->parent->parent->right){
            s = k->parent->parent->left;
            if(s->color == 1){
                s->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else{
                if(k == k->parent->left){
                    k = k->parent;
                    rightRotate(k);
                }

                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotate(k->parent->parent);
            }
        } else{
            s = k->parent->parent->right;
            if(s->color == 1){
                s->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else{
                if(k == k->parent->right){
                    k = k->parent;
                    leftRotate(k);
                }

                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotate(k->parent->parent);
            }
        }

        if(k == root){
            break;
        }
    }
    root->color = 0;

}
public:
Rbtree(){
   tnull = new Node;
   tnull->color = 0;
   tnull->left = tnull->right = nullptr;
   root = tnull;
}

void insert(int data){
    Nodeptr temp = new Node;
    temp->color = 1;
    temp->data = data;
    temp->left = temp->right = tnull;
    temp->parent = nullptr;
    Nodeptr y = nullptr;
    Nodeptr x; 
    x = root; 
    while(x != tnull){
        y = x;
        if(temp->data  < x->data){
            x = x->left;
        } else{
            x = x->right;
        }
    }

    temp->parent = y;

    if(y == nullptr){
       root = temp;
    } else if( temp->data < y->data){
        y->left = temp;
    } else{
        y->right = temp;
    }
    
    if(temp->parent == nullptr){
        temp->color = 0;
        return ;
    }

    if(temp->parent->parent == nullptr){
        return;
    }

    insertFix(temp);
}

void printTree(){
    if(root){
        printHelper(root,"",false);
    }
}
};

int main(){
    Rbtree rb;
    rb.insert(20);
    rb.insert(30);
    rb.insert(16);
    rb.insert(17);

    rb.printTree();

    return 0;
}