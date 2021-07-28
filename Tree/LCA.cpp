#include "/Users/anuragupperwal/stdc++.h"

using namespace std;

struct Node {
    int data;
    Node* left, * right, * parent;
};


class tree{
    public:

    bool srcCheck, destCheck;
    tree() {
        this->srcCheck = false;
        this->destCheck = false;
    }
    Node* inputNode(){ //(int i) {            //I'm unable to understand how to take input recurrsively for a specific number of inputs.
        // if(i<=10){
            int value;
            cin>>value;

            Node* newNode = new Node;

            if(value == -1) return NULL;
            newNode->data = value;
            
            // cout<<"Left of value; "<<value<<" ";
            newNode->left = inputNode();
            // cout<<"Left of right; "<<value<<" ";
            newNode->right = inputNode();

        // }
        return newNode;
    }

    void inorder(Node* root) {
        if(root == NULL) return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

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

    bool find(Node* node, int val) {
        if(node == NULL) return false;

        if(node->data == val || find(node->left, val) || find(node->right, val)) return true;

        return false;
    }

    Node* LCA(Node* root, int src, int dest) {
        Node* LCARes = LCAUtil(root, src, dest);

        Node* temp = new Node;
        temp->data = -1;

        if(srcCheck && destCheck || srcCheck && find(LCARes, dest) || destCheck && find(LCARes, src)) {
            return LCARes;
        }
        else return temp;
    }

    // int distFromRoot(Node* LCA, int val, int dist) {
    //     if(LCA == NULL) return -1;

    //     if(LCA->data == val) return dist;

    //     int d = distFromRoot(LCA->left, val, dist+1);
    //     if(d!= -1) return d;
    //     d = distFromRoot(LCA->right, val, dist+1);
    //     return d;
    // }

    // int minDist(Node* root, int src, int dest, Node* lca) {
    //     if(root == NULL) return -1;

    //     // Node* lca = LCA(root, src, dest);
        
    //     if(lca == NULL) return -1;

    //     int d1 = distFromRoot(lca, src, 0);
    //     int d2 = distFromRoot(lca, dest, 0);
    //     cout<<d1<<" "<<d2<<"\n";

    //     return (d1+d2);

    // }
};

int main() {
    tree t;
    Node* root;
    int src, dest;
    root = t.inputNode();
    t.inorder(root);
    cout<<"\n";
    cin>>src>>dest;
    Node* res = t.LCA(root, src, dest);
    if(res != NULL) cout<<res->data<<"\n";
    else cout<<-1;

    // int ans = t.minDist(root, src, dest, res);
    // if(ans <0) cout<<"ERROR!";
    // else cout<<ans;

    return 0;
}



// 1
// 2
// 4
// 8
// -1
// -1
// 9
// -1
// -1
// 5
// 10
// -1
// -1
// 11
// -1
// -1
// 3
// 6
// -1
// -1
// 7
// -1
// -1



            //                       1
        //                   2             3
        //               4       5        6     7
        //            8   9   10  11   12  13  14  15