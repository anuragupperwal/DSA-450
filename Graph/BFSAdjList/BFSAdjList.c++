#include<iostream>
#include<list>
#include "/Users/anuragupperwal/stdc++.h" //<bits/stdc++.h>

using namespace std;

class Graph {
        int numOfVertices;
        list <int> *l;
        queue <int> q;

    public:
        Graph(int v) {
            this->numOfVertices = v;
            l = new list<int>[numOfVertices];
        }
        void addEdge(int i, int x) {
            l[i].push_back(x);
            l[x].push_back(i);
        }
        void BFSUtil(int i, bool visitCheck[]) {
            if(q.empty()) {
                q.push(i);
                visitCheck[i] = true;
            }

            for(list <int>::iterator j = l[i].begin(); j!=l[i].end(); j++){
                if(!visitCheck[*j]) {
                    q.push(*j);
                    visitCheck[*j] = true;
                }
            }
            
            cout<<q.front()<<" ";
            q.pop();
            if(!q.empty()){
                BFSUtil(q.front(), visitCheck);
            } 
        }
        void BFS(int v) {
            bool visitCheck[numOfVertices];
            for(int i=0; i<numOfVertices; i++) visitCheck[i] = false;

            BFSUtil(v, visitCheck);
        }
};

int main() {                    //Time complexity: V+E (V = no. of vertices, E = no. of edges)
    Graph G1(6);                //Space complexity: O(V), since extra space of size V is required.

    G1.addEdge(1, 2);
    G1.addEdge(1, 4);
    G1.addEdge(2, 3);
    G1.addEdge(2, 4);
    G1.addEdge(3, 4);
    G1.addEdge(3, 5);
    G1.addEdge(4, 5);

    // G1.addEdge(0, 2);
    // G1.addEdge(0, 3);
    // G1.addEdge(1, 3);
    // G1.addEdge(1, 4);
    // G1.addEdge(2, 3);
    // G1.addEdge(2, 4);
    // G1.addEdge(2, 0);
    // G1.addEdge(3, 0);
    // G1.addEdge(3, 1);
    // G1.addEdge(3, 2);
    // G1.addEdge(3, 4);
    // G1.addEdge(4, 1);
    // G1.addEdge(4, 2);
    // G1.addEdge(4, 3);

    G1.BFS(1);

    return 0;
}