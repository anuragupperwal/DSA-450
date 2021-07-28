#include "/Users/anuragupperwal/stdc++.h"

using namespace std;

#define ll long long int 

class Node {
    public:
        ll data, id;
        Node* left, * right;
};

class BST {
    public:
        Node* addEdge(ll height, ll i, ll value, ll n){
            Node* newNode = new Node;
            cout<<height<<" "<<i<<" \n";
            if(i<=height && value<=n){

                newNode->data = value;
                // cout<<value<<" ";
                
                // cout<<"Left of value; "<<value<<" ";
                newNode->left = addEdge(height, i+1, 2*value, n);
                // cout<<"Left of right; "<<value<<" ";
                newNode->right = addEdge(height, i+1, 2*value+1, n);

            }
            else return NULL;

            return newNode;
        }

        Node* inputTree() {
            ll n;
            cin>>n;

            ll height = log2(n);
            Node* newNode = new Node;

            newNode = addEdge(height, 0, 1, n);

            return newNode;
        }

        void inorder(Node *root) {
            if(root == NULL) return;
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }

};


int main() {
    Node* root;
    BST t1;
    root = t1.inputTree();
    t1.inorder(root);
        

    return 0;
}