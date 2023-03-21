// BINARY SEARCH TREE IMPLEMENTATION (BST)

#include<bits/stdc++.h>
using namespace std;

class BST {
    int value;
    BST *left, *right;

public:
    BST() {
        value=0;
        left=right=NULL;
    }

    BST(int val) {
        value=val;
        left=right=NULL;
    }

    BST* insert(BST* root, int val) {
        if(!root) return new BST(val);

        if(val>root->value)
            root->right=insert(root->right, val);
        else if(value<root->value)
            root->left=insert(root->left, val);
        
        return root;
    }

    BST* search(BST* root, int val) {
        if(root==NULL || root->value==val) return root;

        if(root->value<val)
            return search(root->right, val);
        
        return search(root->left, val);
    }

    BST* deleteVal(BST* root, int val) {
        if(!root) return root;

        if(val<root->value) 
            root->left=deleteVal(root->left, val);
        else if(val>root->value)
            root->right=deleteVal(root->right, val);
        else {
            if(root->left==NULL && root->right==NULL)
                return NULL;
            else if(root->left==NULL) {
                BST* tmp=root->right;
                delete(root);
                return tmp;
            }
            else if(root->right==NULL) {
                BST* tmp=root->left;
                delete(root);
                return tmp;
            }

            BST* tmp=root->right;
            while(tmp && tmp->left!=NULL) tmp=tmp->left;
            root->value=tmp->value;
            root->right=deleteVal(root->right, tmp->value);
        }

        return root;
    }

    void displayInorder(BST* root) {
        if(!root) return;
        displayInorder(root->left);
        cout<<root->value<<" ";
        displayInorder(root->right);
    }

};

int main() {
    BST tree, *root=NULL;

    char x;
    do {
        cout<<"1.INSERT  2.SEARCH  3.DISPLAY  4.DELETE"<<endl;
        int option, val;
        cin>>option;

        switch(option) {
            case 1:
                cout<<"Enter value to insert: ";
                cin>>val;
                if(!root) root=tree.insert(root, val);
                else tree.insert(root, val);
                cout<<"Value inserted"<<endl;
                break;
            case 2:
                cout<<"Enter value to search: ";
                cin>>val;
                if(tree.search(root, val)) cout<<"Value found"<<endl;
                else cout<<"Value not found"<<endl;
                break;
            case 3:
                cout<<"Inorder traversal: ";
                tree.displayInorder(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Enter value to delete: ";
                cin>>val;
                tree.deleteVal(root, val);
                cout<<"Value deleted"<<endl;
                break;
            default:
                cout<<"Wrong option"<<endl;
        }

        cout<<"Choose another operation? y/n: ";
        cin>>x;
    } while(x=='y' || x=='Y');

    return 0;
}