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

// class Graph {
//         map <int, map<int, int> > graph;
//         int V, E;
//     public:
//         Graph(int v, int e) {
//             this->V = v;
//             this->E = e;
//         }
//         void AdjMatrix() {
//             int u, v;
//             for(int i=0; i<E; ++i) {
//                 cin>>u>>v;
//                 if(u<=V && v<=V) {
//                     graph[u][v] = 1;
//                     graph[v][u] = 1;
//                 }
//             }
//         }
//         void print() {
//             for(int i=1; i<=V; ++i) {
//                 for(int j=1; j<=V; ++j) {
//                     cout<<graph[i][j];
//                 }
//                 cout<<endl;
//             }
//         }
// };

// int main() {
//     Graph g1(5, 7);
//     g1.AdjMatrix();
//     g1.print();
//     return 0;
// }
