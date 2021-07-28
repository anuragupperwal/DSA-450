// #include<iostream>
#include"/Users/anuragupperwal/stdc++.h"
using namespace std;

#define ll long long int
class Node {
    public:
        ll value;
        Node* left, *right, *parent;
        // Node() {
        //     left = new Node;
        //     right = new Node;
        //     parent = new Node;
        // }
};

class Tree {
    public:
        void insertNode(Node **root, Node *newNode) {
            if(*root == NULL) {
                *root = newNode;
            }
            else {
                Node *temp = *root;
                if(temp->value > newNode->value) {
                    if(temp->left == NULL) temp->left = newNode;
                    else insertNode(&temp->left, newNode);
                }
                else {
                    if(temp->right == NULL) temp->right = newNode;
                    else insertNode(&temp->right, newNode);
                }
            }
        }
        void BST(Node **root) {
            // Node *newNode = new Node;
            // for(ll i=1; i<4; ++i) {
            //     // newNode->value = i;
            //     cin>>newNode->value;
            //     cout<<newNode->value<<" ";
            //     insertNode(&*root, newNode);
            // }

            ll conti=1;
            do {          
                Node *newNode = new Node;
                newNode->value = conti;
                insertNode(&*root, newNode);      
                ++conti;
                // cout<<newNode->value<<" ";
            } while(conti!=10);
        }
        void inorder(Node *root) {
            if(root==NULL) return;

            inorder(root->left);
            cout<<root->value<<" ";
            inorder(root->right);
        }
        // int findLeafNodes(Node **root, vector <ll> leafNodes) {
        //     if(*root == NULL) return 0;
        //     Node* temp = *root;
        //     if(temp->left == NULL) leafNodes.push_back(temp->left->value);

        //     return 0;
        // }
};


int main() {
    Tree t1;
    Node *root = new Node;
    vector <ll> leafNodes;

    t1.BST(&root);
    t1.inorder(root);
    // findLeafNodes(&*root, leafNodes);




    // vector <int> v;
    // for(int i=0; i<10000000; ++i) {
    //     // cout<<i<<" ";
    //     v.push_back(i);
    // }   
    // for(int i=0; i<10000000; ++i) {
    //     cout<<v[i]<<" ";
    // }
    return 0;
}