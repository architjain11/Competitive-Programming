// QUEUES USING LINKED LIST

#include<bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node* next;
}*front=NULL, *rear=NULL;

bool isempty() {
    if(front==NULL && rear==NULL) return true;
    return false;
}

void enqueue(int value) {
    node* newNode=new node();
    newNode->value=value;
    newNode->next=NULL;
    if(front==NULL) {
        front=newNode;
        rear=newNode;
    }
    else {
        rear->next=newNode;
        rear=newNode;
    }
    cout<<"Enqueued to queue"<<endl;
}

void dequeue() {
    if(isempty()) {
        cout<<"Queue is empty";
        return;
    }
    if(front==rear) {
        delete(front);
        front=rear=NULL;
    }
    else {
        node* toBeDequeued=front;
        front=front->next;
        delete(toBeDequeued);
    }
    cout<<"Dequeued"<<endl;
}

void showFront() {
    if(isempty()) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<front->value<<endl;
}

void display() {
    if(isempty()) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    node* traverse=front;
    cout<<"(Front) ";
    while(traverse!=NULL) {
        cout<<traverse->value<<" ";
        traverse=traverse->next;
    }
    cout<<"(Rear)"<<endl;
}

int main() {
    char x;
    do {
        cout<<"1.ENQUEUE  2.DEQUEUE  3.DISPLAY  4.ISEMPTY  5.FRONT"<<endl;
        int option;
        cin>>option;

        switch(option) {
            case 1:
                cout<<"Enter value: ";
                int value; cin>>value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout<<(isempty()?"Yes":"No")<<endl;
                break;
            case 5:
                showFront();
                break;
            default:
                cout<<"Wrong option"<<endl;
        }

        cout<<"Choose another operation? y/n: ";
        cin>>x;
    } while(x=='y' || x=='Y');

    return 0;
}