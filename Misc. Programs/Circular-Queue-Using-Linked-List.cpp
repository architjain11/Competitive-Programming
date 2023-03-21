// CIRCULAR QUEUE USING LINKED LIST

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data=value;
        next=NULL;
    }
}*front=NULL, *rear=NULL;

class Queue {
public:
    void enqueue(int value) {
        Node* newNode= new Node(value);
        if(front==NULL) front=newNode;
        else rear->next=newNode;
        rear=newNode;
        rear->next=front; //circular connection
    }

    void dequeue() {
        if(front==NULL) {
            cout<<"Queue empty"<<endl;
            return;
        }
        
        if(front==rear) {
            delete(front);
            front=rear=NULL;
        }
        else {
            Node* tmp=front;
            front=front->next;
            rear->next=front;
            delete(tmp);
        }
        return;
    }

    void display() {
        Node* tmp=front;
        while(tmp->next!=front) {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<tmp->data<<endl;
    }
};

int main() {
    Queue q;
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(10);
    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}