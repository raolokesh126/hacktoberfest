#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data=d;
        this -> next=NULL;
    }

    ~Node(){
        int val =this -> data;

        if(this -> next!=NULL){
            delete next;
            next=NULL;
        }
    }
};

void insertNode(Node* &tail,int element,int d){
    if(tail==NULL){
        Node* newnode=new Node(d);
        tail=newnode;
        newnode -> next=newnode;
    }
    else{
        Node* curr=tail;
        while(curr -> data!=element){
            curr=curr -> next;
        }
        Node* temp=new Node(d);
        temp -> next=curr -> next;
        curr -> next=temp;
    }
}

void deletenode(Node* &tail,int element){
    if(tail==NULL){
        cout<<"List is already empty!"<<endl;
        return;
    }
    Node* prev=tail;
    Node* curr=prev -> next;

    while(curr-> data!=element){
        prev=curr;
        curr=curr -> next;
    }

    prev -> next=curr -> next;
    if(prev==curr){
        tail=NULL;
    }

    else if(tail==curr){
        tail=prev;
    }

    curr -> next =NULL;
    delete curr;
}

bool iscircular(Node* tail){
    if(tail==NULL){
        return true;
    }

    Node* temp=tail -> next;
    while(temp!=NULL && temp!=tail){
        temp=temp -> next;
    }
    if(temp==NULL){
        return false;
    }

    return true;
}

void print(Node* tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"List id empty!"<<endl;
    }

    do{
        cout<<temp->data<<" ";
        temp=temp-> next;
    }while(tail !=temp);
    cout<<endl;
}

int main(){
    Node* tail=NULL;

    insertNode(tail,0,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,3,10);
    print(tail);

    insertNode(tail,5,0);
    print(tail);

    deletenode(tail,5);
    print(tail);

    insertNode(tail,0,7);
    print(tail);
    
    if(iscircular(tail))
    cout<<"List is circular!";

    else
    cout<<"List is not circular!";

    return 0;
}