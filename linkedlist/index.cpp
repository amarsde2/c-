#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node *next;

   Node(int value){
      data = value;
      next = NULL;
   }
};

void insertAtBeginner(Node* &head, int value){
    Node * temp = new Node(value);
    temp->next = head;
    head = temp;
}

void deleteAtPosition(Node* &head, int key){
    
    if(head == NULL){
       return;
    }
    
    Node *ptr = head;
    bool flag = false;
    Node *deleteNode = head;



    if(head->data == key){
       head = head->next;
       delete deleteNode;
    } else{
      while(ptr->next != NULL){
        if(ptr->next->data == key){
           flag = true;
           break;
        }
        ptr = ptr->next;
      }
    }

    if(flag == true){
       deleteNode = ptr->next;
       ptr->next = ptr->next->next;
       delete deleteNode;
    } else{
        cout << "Not found " << endl;
    }
    return;
}

void insertAtEnd(Node* &head, int value){
    Node *temp = new Node(value);
    Node *ptr = head;

    if(head == NULL){
        head = temp;
    }

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = temp;
    
}

void display(Node * head){
    Node *ptr = head;
    
    while(ptr != NULL){
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

void createCycle(Node * &head, int key){
    Node *temp = head;
    Node *startpoint = NULL;

    while(temp->next != NULL){
        if(temp->next->data == key){
            startpoint = temp->next;
        }
        temp = temp->next;
    }
    
    temp->next = startpoint;
}

bool detectCycle(Node *head){
    Node *slow = head;
    Node *fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
         return true;
        }
    }
    return false;
}

void removeCycle(Node * &head){
    Node *slow = head;
    Node *fast = head;    

    do{
        slow  = slow->next;
        fast = fast->next->next;
    }while(slow != fast);
    
    fast = head;

    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

int main(){
    Node *head = NULL;
    insertAtBeginner(head, 23);
    insertAtBeginner(head, 25);
    insertAtBeginner(head, 75);
    insertAtEnd(head, 29);
    //deleteAtPosition(head, 25);
    //deleteAtPosition(head, 29);
    display(head);
    createCycle(head, 25);
    
    if(detectCycle(head)){
        cout << "Cycle find"<<endl;
        removeCycle(head);
    } else{
        cout << "Cycle Not found " << endl;
    }

    display(head);

    return 0;
}