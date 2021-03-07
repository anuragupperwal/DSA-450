#include<iostream>
#include<map>
#include<cctype>

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