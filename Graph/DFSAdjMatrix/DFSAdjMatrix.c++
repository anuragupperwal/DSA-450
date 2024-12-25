#include<iostream>
#include<map>
#include "/Users/anuragupperwal/stdc++.h" //<bits/stdc++.h>

using namespace std;

int GraphInput(map<int, map<int, int> > &graphMap, int numOfNodes, int totalElements, int count) {
    if(count < totalElements) {
        int i, j;
        char conti;
        // cout<<"Enter adjacent elements: ";
        cin>>i>>j;
        if(i<=numOfNodes && j<=numOfNodes) {
            graphMap[i][j] = 1;
            graphMap[j][i] = 1;
        }
        
        // cout<<"Enter again? (Y = yes, N = no: ";
        cin>>conti;
        if(conti == 'n' || conti == 'N') return 0;

        return GraphInput(graphMap, numOfNodes, totalElements, ++count);
    }

    return 0;
}

int DFS(map<int, map<int, int> > graphMap, map<int, char> &visitCheck, stack <int> &s, int numOfNodes, int i) {
    if(i<=numOfNodes) {
        s.push(i);
        visitCheck[i] = 'g';
        for(int j=1; j<=numOfNodes; ++j) {
            if(graphMap[i][j] == 1) {
                if(visitCheck[j] == 'w') {
                    i = j;
                    i = DFS(graphMap, visitCheck, s, numOfNodes, i);
                }
            }
        }
        visitCheck[i] = 'b';
        cout<<s.top();
        s.pop();
        if(!s.empty()) return s.top();
        else return 0;
    }
    return 0;
}

int main() {
    map<int, map<int, int> > graphMap;
    map<int, char> visitCheck;
    stack <int> s;

    int numOfNodes;
    cin>>numOfNodes;

    GraphInput(graphMap, numOfNodes, numOfNodes*numOfNodes, 0);

    for(int i=1; i<=numOfNodes; ++i) {
        visitCheck[i] = 'w';
    }

    DFS(graphMap, visitCheck, s, numOfNodes, 1);

    // DFS(graphMap, numOfNodes);

    //using the default way to iterate over map
    // cout<<"Advacency matrix: \n";
    // for(map<int, map<int, pair<int, int> > >::const_iterator itr1=graphMap.begin(); itr1!=graphMap.end(); ++itr1) {
    //     cout<<itr1->first<<" ";
    //     for(map<int, map<int, pair<int, int> > >::const_iterator itr2= itr1->second.begin(); itr2!=itr1->second.begin(); itr2++) {
    //         cout<<itr2->first<<" ";
    //     }
    // }

    cout<<"\n";
    for(int i=1; i<=numOfNodes; ++i) {
        for(int j=1; j<=numOfNodes; ++j) {
                cout<<graphMap[i][j]<<" ";
        }
        cout<<endl;
    } 

    // for(int i=1; i<=numOfNodes; ++i) {
    //     cout<<i<<" "<<visitCheck[i]<<endl;
    // } 

    return 0;
}