#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node *next;
   Node *prev;

   Node(int value){
    data = value;
    next = NULL;
    prev = NULL;
   }
};


void insertAtBegin(Node * &head, int key){
    Node *temp = new Node(key);
    temp->next = head;
    if(head != NULL){
      head->prev = temp;
    }
    head = temp;
}



void display(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int getLength(Node * head){
    int count = 0;
    Node *ptr = head;

    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}
Node * appendKNode(Node * head, int k){
    int len = getLength(head);
    
    k = k % len;

    Node* tail = head;
    Node* newHead;
    Node* newtail;
   
    int count = 1;
    
    while(tail->next != NULL){
        if(count == len - k){
            newtail = tail;
        }       

        if(count  == len - k + 1){
            newHead = tail;
        }

        count++;
        tail = tail->next;
    }

    newtail->next = NULL;
    tail->next = head;
    return newHead;

}

void createInsert(Node *&head1, Node *&head2, int pos){
    Node *temp1 = head1;
    Node *temp2 = head2;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }

    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int findLength(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
       count++;
       temp = temp->next;
    }
    return count;
}

int findInterest(Node * head, Node * head2){
    int l1 = findLength(head);
    int l2 = findLength(head2);
    Node *ptr1, *ptr2;
    int d;
    if(l2 > l1){
        
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head;

    } else{
        
        d = l1-l2;
        ptr1 = head;
        ptr2 = head2;
    
    }
    
    while(d){
        ptr1 = ptr1->next;
        d--;
    }

    while(ptr1 != NULL && ptr2 != NULL){
          if(ptr1 == ptr2){
            return ptr1->data;
          }
          ptr1 = ptr1->next;
          ptr2 = ptr2->next;
    }

    return -1;
}

int main(){

    Node *head1 = NULL;
    Node *head2 = NULL;
    insertAtBegin(head1, 24);
    insertAtBegin(head1, 23);
    insertAtBegin(head1, 22);
    insertAtBegin(head1, 21);
    insertAtBegin(head1, 20);
    insertAtBegin(head1, 19);
    insertAtBegin(head2, 18);
    insertAtBegin(head2, 17);
    createInsert(head1, head2, 3);
    
    int find = findInterest(head1, head2);
    
    if(find == -1){
        cout << "Interset not found" << endl;
    } else{ 
        cout << find << endl;
    }

    return 0;
}