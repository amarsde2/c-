#include<bits/stdc++.h>
using namespace std;

class BtreeNode{
    int t; // order of node
    int *keys; // array to store keys
    bool leaf;
    BtreeNode **childs;
    int n;
    public:

    BtreeNode(int t1, bool leafa){
        t = t1;
        leaf = leafa;
        keys = new int[2*t-1];
        childs = new BtreeNode *[2*t];
        n = 0;
    }
    public:
    int findIndex(int key);
    void display();
    void deletion(int key);
    void merge(int index);
    int precessdor(int key);
    int successor(int key);
    void BrrowFromPrev(int index);
    void BrrowFromNext(int index);
    void deleteFromLeaf(int index);
    void deleteFromNonLeaf(int index);
    void fill(int index);
    void split(int index, BtreeNode *node);
    void insertNotNULL(int key);

    friend class Btree;

};

void BtreeNode::deleteFromLeaf(int key){
     
    for(int i = key+1; i < n; i++){
        keys[i-1] = keys[i];
    }
    n--;
}

int BtreeNode::precessdor(int index){
    BtreeNode *node = childs[index];
    while(node->leaf == false){
        node = node->childs[n];
    }
    return node->keys[n-1];
}


int BtreeNode::successor(int index){
    BtreeNode *node = childs[index+1];
    while(node->leaf == false){
        node = node->childs[0];
    }
    return node->keys[0];
}

void BtreeNode::deleteFromNonLeaf(int key){
    int k = keys[key];
    if(childs[key]->n >= t){
        int pre = precessdor(key);
        keys[key] = pre;
        childs[key]->deletion(pre);
    } else if(childs[key+1]->n >= t){
        int sus = successor(key);
        keys[key] = sus;
        childs[key+1]->deletion(sus);
    } else{
        merge(key);
        childs[key]->deletion(k);
    } 
}

void BtreeNode::merge(int idx){
    BtreeNode *child = childs[idx];
    BtreeNode *sibling = childs[idx + 1];
    child->keys[t-1] = keys[idx];
    for(int i = 0; i < sibling->n ; i++){
        child->keys[i+t] = sibling->keys[i];
    }

    if(child->leaf == false){
        for(int i = 0; i <= sibling->n ; i++){
           child->childs[i+t] = sibling->childs[i];
        }
    }

    if(sibling->leaf == false){
        for(int i = 0; i <= sibling->n ; i++){
            sibling->childs[i] = NULL;
        }
    }

    for(int i = idx+1; i < n; ++i){
        keys[i-1] = keys[i];
    }

    for(int i = idx+2 ; i <= n; ++i){
        childs[i-1] = childs[i];
    }
    child->n = child->n + sibling->n + 1;
    n--;
    delete sibling;

    return;
}

void BtreeNode::split(int index, BtreeNode *y){
    BtreeNode *right = new BtreeNode(t,y->leaf);
    right->n = t-1;
    for(int i = 0; i < t-1; i++){
        right->keys[i] = y->keys[i+t]; 
    }
    if(y->leaf == false){
       for(int i = 0 ; i < t; i++){
          right->childs[i] = y->childs[i+t]; 
       }
    }
    y->n  = t-1;

    // let make a room for insert middle of y into parent
    
    for(int j = n-1; j >= index; j--){
        keys[j+1] = keys[j];
    }

    for(int j = n; j >= index+1; j--){
       childs[j+1] =  childs[j];
    }
    
    
    childs[index+1] = right;
    keys[index] =  y->keys[t-1]; 
    n = n+1;
}

void BtreeNode::display(){
    int i;
    for(i = 0; i < n; i++){
        if(leaf == false){
            childs[i]->display();
        }
        cout << keys[i] << endl;
    }

    if(leaf == false){
        childs[i]->display();
    }
}



class Btree{ 
    int t;
    BtreeNode *root;
    public:
    Btree(int t1){
        t = t1;
        root = NULL;
    }
    
    void insert(int key);

    void display(){
        if(root != NULL){
            root->display();
        }
    }

    void deletion(int key);
};

int BtreeNode::findIndex(int key){
    int i = 0;
    while(i < n && key > keys[i]){
        ++i;
    }
    return i;
}

void BtreeNode::BrrowFromPrev(int key){
    BtreeNode *child = childs[key];
    BtreeNode *sibling = childs[key-1];

     //make space
    for(int i = child->n-1; i >= 0; i--){
      child->keys[i+1] = child->keys[i];
    }

    if(child->leaf == false){
        for(int i = child->n; i >= key; i--){
         child->childs[i+1] = child->childs[i];
        }
    }

    child->keys[0] = keys[key-1];

    if(child->leaf == false){
        child->childs[0] = sibling->childs[sibling->n];
    }

    keys[key-1] = sibling->keys[sibling->n-1];

    child->n++;
    sibling->n--;

    return;
}


void BtreeNode::BrrowFromNext(int key){
    BtreeNode *child = childs[key];
    BtreeNode *sibling = childs[key+1];

     //make space
   
    child->keys[child->n] = keys[key];
    keys[key] = sibling->keys[0];

    if(child->leaf == false){
        child->childs[(child->n)+1] = sibling->childs[0];
        for(int i = 1; i < sibling->n; i++){
          sibling->keys[i-1] = sibling->keys[i];
        }
    }  

    if(sibling->leaf == false){
        for(int i = 1; i <= sibling->n; i++){
           sibling->childs[i-1] = sibling->childs[i];
        }
    }

    child->n++;
    sibling->n--;

    return;
}

void BtreeNode::fill(int idx){
    if(idx != 0 && childs[idx-1]->n >= t){
       BrrowFromPrev(idx);
    } else if(idx != n && childs[idx+1]->n >= t){
       BrrowFromNext(idx);
    } else{
        if(idx != n){
           merge(idx);
        }else{
           merge(idx-1);
        }
    }
}

void BtreeNode::deletion(int key){
  
    int idx = findIndex(key);

    if (idx < n && keys[idx] == key) {
        if (leaf) {
            deleteFromLeaf(idx);
        } else {
            deleteFromNonLeaf(idx);
        }
    } else {
        if (leaf) {
            cout << "The key " << key << " is not present in the tree\n";
            return;
        }

       
        if (childs[idx]->n < t)
            fill(idx);

        if (idx > n)
            childs[idx - 1]->deletion(key);
        else
            childs[idx]->deletion(key);
    }
}


void Btree::deletion(int key){
    if(!root){
        cout << "ERROR: No key found " << endl;
        return ;
    } else{
       
        root->deletion(key);

        if(root->n == 0){
            BtreeNode *temp = root;

            if(root->leaf == true){
                root = NULL;
            } else{

                root = root->childs[0];
            }

            delete temp;
        }
    }
    return;
}
void BtreeNode::insertNotNULL(int key){
  
    int i = n-1;

    if(leaf == true){
        while(i >= 0 && keys[i] > key){
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = key;
        n = n +1;
    } else{
        
        while(i >= 0 && keys[i] > key){
            i--;
        }
        
      
        if(childs[i+1]->n == 2 * t-1){
            split(i+1, childs[i+1]);
            if(keys[i+1] < key){
              i++;
            }
        }
        
        childs[i+1]->insertNotNULL(key);
        
    }
}

void Btree::insert(int key){
 
    if(root == NULL){
        root = new BtreeNode(t,true);
        root->keys[0] = key;
        root->n  = 1;
    } else{
        if(root->n == 2 * t -1){
            BtreeNode *super = new BtreeNode(t, false);
            super->childs[0] = root;
            super->split(0, root);
            int i = 0;
            if(super->keys[0] < key){
                i++;
            }
            super->childs[i]->insertNotNULL(key);
            root = super;
            cout << "data is " << key << endl;
        } else{
            cout << "Data if " <<  key << endl;
            root->insertNotNULL(key);
        }
    }
}

int main(){
    Btree t(3);
    t.insert(8);
    t.insert(9);
    t.insert(10);
    t.insert(11);
    t.insert(15);
    t.insert(16);
    t.insert(17);
    t.insert(18);
    t.insert(20);
    t.insert(23);
    cout << "Insertion Done";
    cout << "\nBTree elements before deletion: "<<endl;
    t.display();
    int ele = 20;
    cout << "\nThe element to be deleted: "<<ele;
    t.deletion(20);   
    cout << "\nBTree elements before deletion: "<<endl;
    t.display();
    return 0;
}