#include "/Users/anuragupperwal/stdc++.h"

using namespace std;

#define ll long long int 

class Node {
    public:
        ll data;
        Node* left, * right;
};

class BT {
    public: 
        vector <pair <int, int> > treeVec;
        map <int, Node*> tree;
        Node* inputNode() {
            int n;
            cin>>n;

            //to input edges in vector
            for(int i=0; i<n-1; ++i) {
                pair <int, int> a;
                cin>>a.first>>a.second;
                treeVec.push_back(make_pair(a.first, a.second));
            }
            
            //to create a map with all the vectices of the tree with their address.
            for(int i=0; i<n-1; ++i) {
                map <int, Node*>::iterator it1 = tree.find(treeVec[i].first);
                map <int, Node*>::iterator it2 = tree.find(treeVec[i].second);
                if(it1 == tree.end()) {
                    cout<<"Not found!\n";
                    Node* newNode = new Node;
                    tree[treeVec[i].first] = newNode;
                    tree[treeVec[i].first]->data = treeVec[i].first;
                    tree[treeVec[i].first]->right = NULL;
                    tree[treeVec[i].first]->left = NULL;
                }
                if(it2 == tree.end()) {
                    cout<<"Not found!\n";
                    Node* newNode = new Node;
                    tree[treeVec[i].second] = newNode;
                    tree[treeVec[i].second]->data = treeVec[i].second;
                    tree[treeVec[i].second]->right = NULL;
                    tree[treeVec[i].second]->left = NULL;
                }
            }

            // // to print the entire tree.
            // for(auto it = tree.begin(); it!=tree.end(); ++it) {
            //     cout<<it->first<<" "<<it->second<<" "<<it->second->data<<"\n";
            // }


            //to connects the edge of the vertices.
            for(int i=0; i<n-1; ++i) {
                cout<<"---- "<<treeVec[i].first<<" "<<treeVec[i].second<<"\n";
                if(tree[treeVec[i].first]->left == NULL) {
                    tree[treeVec[i].first]->left = tree[treeVec[i].second];

                    cout<<"--if-- \t"<<tree[treeVec[i].first]->data<<" "<<tree[treeVec[i].first]->left<<" "<<tree[treeVec[i].first]->right<<"\n";
                }
                else {
                    tree[treeVec[i].first]->right = tree[treeVec[i].second];
                    cout<<"--else-- "<<tree[treeVec[i].first]->data<<" "<<tree[treeVec[i].first]->left<<" "<<tree[treeVec[i].first]->right<<"\n";
                }
            }
            return tree[1];
        }

        void inorder(Node *root) {
            if(root==NULL) return;

            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }

        ll treeSum(Node* root) {
            if(root == NULL) return 0;

            ll left = treeSum(root->left);
            ll right = treeSum(root->right);

            return (root->data+left+right);
        }

        ll treeMax(Node* root) {
            if(root == NULL) return 0;

            ll left = treeMax(root->left);
            ll right = treeMax(root->right);
            return max(root->data, left, right);
        }

        ll treeHeight(Node* root) {
            if(root == NULL) return 0;

            ll left = treeHeight(root->left);
            ll right = treeHeight(root->right);
            return max(left, right) + 1;
        }

        bool existInTree(Node* root, ll value) {
            if(root == NULL ) return false;

            bool left = existInTree(root->left, value);
            bool right = existInTree(root->right, value);

            if(value == root->data || value == left || value == right) return true;
        }

        void reverseTree(Node* root) {
            if(root == NULL ) return;

            reverseTree(root->left);
            reverseTree(root->right);
            Node* newNode = new Node;
            newNode = root->left;
            root->left = root->right;
            root->right = newNode;
        }

    
};


int main() {
    BT t1;
    Node* root;
    root = t1.inputNode();

    t1.inorder(root);
    t1.reverseTree(root);
    t1.inorder(root);
    cout<<t1.treeHeight(root)<<"\n";
    t1.inorder(root);
    cout<<t1.treeMax(root)<<"\n";
    t1.inorder(root);
    cout<<t1.treeSum(root)<<"\n";
    t1.inorder(root);

    ll val;
    cin>>val;
    cout<<t1.existInTree(root, val)<<"\n";
    t1.inorder(root);

    return 0;
}