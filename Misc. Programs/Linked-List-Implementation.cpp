// LINKED LIST IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data=value;
        next=NULL;
    }
}*head=NULL, *curr=NULL;

class linkedList {
public:
    void insert(int value) {
        Node* newNode= new Node(value);
        if(head==NULL) {
            head=newNode;
            curr=head;
        }
        else curr->next=newNode;
        curr=newNode;
    }

    void deleteNode(int value) {
        Node* current=head;
        int index=0;
        while(current!=NULL && current->data!=value) {
            index++;
            current=current->next;
        }

        if(current==NULL) {
            cout<<"Node "<<value<<" not found in linked list"<<endl;
            return;
        }

        current=head;
        if(!index) head=head->next; //if first node deleted
        else {
            index--;
            while(index--) {
                current=current->next;
            }
            Node* tmp=current->next;
            if(tmp->next==NULL) curr=current; //if last node deleted

            current->next=tmp->next;
            delete(tmp);
        }

        cout<<"Node "<<value<<" deleted"<<endl;
        return;
    }

    void search(int value) {
        Node* tmp=head;
        while(tmp!=NULL && tmp->data!=value)
            tmp=tmp->next;
        if(tmp!=NULL) cout<<"Value "<<value<<" found"<<endl;
        else cout<<"Value "<<value<<" not in linked list"<<endl;
    }

    void display() {
        Node* tmp=head;
        while(tmp!=NULL) {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
};

int main() {
    linkedList ll;
    ll.insert(20);
    ll.insert(30);
    ll.insert(10);
    ll.insert(40);
    ll.display();

    ll.search(20);
    ll.search(50);

    ll.deleteNode(40);
    ll.deleteNode(20);
    ll.display();

    ll.insert(50);
    ll.insert(90);
    ll.display();

    return 0;
}