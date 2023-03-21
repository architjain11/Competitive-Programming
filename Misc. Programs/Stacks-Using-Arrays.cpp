// STACKS USING ARRAYS

#include<bits/stdc++.h>
using namespace std;

#define maxsize 5

class Stack {
    int arr[maxsize];
    int top;
    
public:
    Stack() {
        top=-1;
    }

    bool isfull() {
        if(top==maxsize-1) return true;
        return false;
    }

    bool isempty() {
        if(top==-1) return true;
        return false;
    }

    void push(int value) {
        if(isfull()) {
            cout<<"Cannot push new element, stack is full"<<endl;
            return;
        }
        top++;
        arr[top]=value;
        cout<<"Pushed into stack"<<endl;
    }

    void pop() {
        if(isempty()) {
            cout<<"Stack is empty"<<endl;
            return;
        }
        top--;
        cout<<"Popped stack"<<endl;
        return;
    }

    void top_element() {
        if(isempty()) {
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<arr[top]<<endl;;
    }

    int size() {
        return top+1;
    }

    void display() {
        if(isempty()) {
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i=0; i<=top; i++) cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
};
    
int main() {
    Stack s;
    char x;


    do {
        cout<<"1.PUSH  2.POP  3.PRINT  4.ISFULL  5.ISEMPTY  6.TOP  7.SIZE"<<endl;
        int option;
        cin>>option;

        switch(option) {
            case 1:
                cout<<"Enter value: ";
                int value; cin>>value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout<<(s.isfull()?"Yes":"No")<<endl;
                break;
            case 5:
                cout<<(s.isempty()?"Yes":"No")<<endl;
                break;
            case 6:
                s.top_element();
                break;
            case 7: 
                cout<<s.size()<<endl;
                break;
            default:
                cout<<"Wrong option"<<endl;
        }

        cout<<"Choose another operation? y/n: ";
        cin>>x;
    } while(x=='y' || x=='Y');
    


    return 0;
}