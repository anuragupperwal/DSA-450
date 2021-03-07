#include<iostream>
#include<map>
#include "/Users/anuragupperwal/stdc++.h"

using namespace std;

void graphInput(map<int, map<int, int> > &graphMap, int i, int j)  {
    graphMap[i][j] = 1;
    graphMap[j][i] = 1;
}

int BFS(map<int, map<int, int> > graphMap, map<int, char> &visitCheck, vector <int> &rtn, queue <int> &q, int numOfVertices, int i) {
    int k=0;   //
    if(i<=numOfVertices) {
        if(q.empty()) {
            q.push(i);
            visitCheck[i] = 'b';
        }
        
        for(int j=1; j<=numOfVertices; ++j) {
            if(graphMap[i][j] == 1) {
                if(visitCheck[j] == 'w') {
                    q.push(j);
                    visitCheck[j] = 'b';
                }
            }
            
        }
        rtn.push_back(q.front());
        q.pop();
        if(!q.empty()){
            i = q.front();
            BFS(graphMap, visitCheck, rtn, q, numOfVertices, i);
        }
        return 0;   
    }
    return 0;
}

int main() {
    map<int, map<int, int> > graphMap;
    map<int, char> visitCheck;
    vector <int> rtn;
    queue <int> q;

    int numOfVertices=5;
    // cin>>numOfVertices;

    graphInput(graphMap, 1, 2);
    graphInput(graphMap, 1, 4);
    graphInput(graphMap, 2, 1);
    graphInput(graphMap, 2, 3);
    graphInput(graphMap, 2, 4);
    graphInput(graphMap, 3, 4);
    graphInput(graphMap, 3, 5);
    graphInput(graphMap, 4, 5);

    for(int i=0; i<=numOfVertices; ++i) {
        visitCheck[i] = 'w';
    }
    BFS(graphMap, visitCheck, rtn, q, numOfVertices, 1);

    for(int i=0; i<rtn.size(); ++i) {
        cout<<rtn[i]<<" ";
    }
    return 0;
}






















// void graphInput(map<int, map<int, int> > &graphMap, int numOfVertices) {
//     char conti='y';
//     while(conti == 'y' || conti=='Y') {
//         int i, j;
//         cout<<"Enter adjacent nodes: ";
//         cin>>i>>j;
//         graphMap[i][j] = 1;
//         graphMap[j][i] = 1;

//         cout<<"Want to continue? (y/n): ";
//         cin>>conti;
//     }
// }