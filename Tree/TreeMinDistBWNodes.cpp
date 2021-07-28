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
        bool srcCheck, destCheck;
        BT() {
            this->srcCheck = false;
            this->destCheck = false;
        }

        //to input graph in random ordered edge by user (Binary tree)
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

        //to print graph in inordered form
        void inorder(Node *root) {
            if(root==NULL) return;

            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }

        //Lowest commen ancestor util fun to find LCA
        Node* LCAUtil(Node* root, int src, int dest){
            if(root == NULL) return NULL;

            if(root->data == src) {
                srcCheck = true;
                return root;
            }
            if(root->data == dest) {
                destCheck = true;
                return root;
            }

            Node* leftLCA = LCA(root->left, src, dest);
            Node* rightLCA = LCA(root->right, src, dest);

            if(leftLCA!= NULL && rightLCA!= NULL) return root;
            return (leftLCA != NULL)? leftLCA : rightLCA;
        }

        //to find if a node exist in the tree.
        bool find(Node* node, int val) {
            if(node == NULL) return false;

            if(node->data == val || find(node->left, val) || find(node->right, val)) return true;

            return false;
        }

        //to find Lowest common ancestor of src and dest nodes
        Node* LCA(Node* root, int src, int dest) {
            Node* LCARes = LCAUtil(root, src, dest);

            Node* temp = new Node;
            temp->data = -1;

            //to check if both the nodes exist in the tree
            if(srcCheck && destCheck || srcCheck && find(LCARes, dest) || destCheck && find(LCARes, src)) {
                return LCARes;
            }
            else return temp;
        }

        //to find the distance of a node from the root node.
        int distFromRoot(Node* LCA, int val, int dist) {
            if(LCA == NULL) return -1;

            if(LCA->data == val) return dist;

            int d = distFromRoot(LCA->left, val, dist+1);
            if(d!= -1) return d;
            d = distFromRoot(LCA->right, val, dist+1);
            return d;
        }

        //to find the minimum distance between two nodes in a tree.
        int minDist(Node* root, int src, int dest) {
            if(root == NULL) return -1;

            Node* lca = LCA(root, src, dest);
            
            if(lca == NULL) return -1;

            int d1 = distFromRoot(lca, src, 0);
            int d2 = distFromRoot(lca, dest, 0);
            // cout<<d1<<" "<<d2<<"\n";

            return (d1+d2);

        }
    
};


int main() {
    BT t;
    Node* root;
    int src, dest;
    //to input node
    root = t.inputNode();
    //to print tree
    t.inorder(root);
    cout<<"\n";
    cin>>src>>dest;

    //function call to find minimum dist between 2 nodes
    int ans = t.minDist(root, src, dest);
    if(ans <0) {}//cout<<"ERROR!";
    else cout<<ans;

    return 0;
}
