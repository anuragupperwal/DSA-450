#include<iostream>
#include<map>
// #include<cctype>

using namespace std;

map<int, map<int, int> > graphMap;

int GraphInput(int numOfNodes, int totalNodes, int count) {
    if(count<totalNodes) {
        int i, j;
        char conti;
        cout<<"Enter adjacent elements: \n";
        cin>>i>>j;
        if(i<=numOfNodes && j<= numOfNodes) {
            graphMap[i][j] = 1;
            graphMap[j][i] = 1;
        }
        else {
            cout<<"Out of bound!!\n";
        }
        
        cout<<"Want to add more nodes? (Y - yes, N - no): ";
        cin>>conti;
        if(conti== 'n') return 0;

        return GraphInput(numOfNodes, totalNodes, ++count);
    }
    return 0;
}

int main() {
    int numOfNodes;
    cin>>numOfNodes;

    GraphInput(numOfNodes, numOfNodes*numOfNodes, 1);

    // cout<<"Adjacent nodes\n";
    // for(int i=1; i<=numOfNodes; ++i) {
    //     for(int j=1; j<=numOfNodes; ++j) {
    //         if(graphMap[i][j] == 1) cout<<i<<" - "<<j<<"\n";
    //     }
    // }

    cout<<"Advacency matrix: \n";
    for(int i=1; i<=numOfNodes; ++i) {
        for(int j=1; j<=numOfNodes; ++j) {
            cout<<graphMap[i][j];
        }
        cout<<endl;
    }
    return 0;
}



//Using class

// class AdjMatrix {
//         int v, e;
//         map <int, map<int, int> > matrix;
//     public:
//         AdjMatrix(int a, int b) {
//             v = a; 
//             e = b;
//         }
//         void adjMat() {
//             int a, b;
//             for(int i=0; i<e; ++i) {
//                 cin>>a>>b;
//                 matrix[a][b] = 1;
//                 matrix[b][a] = 1;
//             }
//         }
//         void print() {
//             for(int i=0; i<v; ++i) {
//                 for(int j=0; j<v; ++j) {
//                     cout<<matrix[i][j]<<" ";
//                 }
//                 cout<<endl;
//             }
//         }

// };

// int main() {
//     AdjMatrix a1(5, 7);
//     a1.adjMat();
//     a1.print();
//     return 0;
// }
