#include<iostream>
#include<list>

using namespace std;

class Graph {
        int numOfVertices;
        list <int> *l;
        // queue <int> q;

    public:
        Graph(int v) {
            this->numOfVertices = v;
            l = new list<int>[numOfVertices];
        }
        void addEdge(int i, int x) {
            l[i].push_back(x);
        }
        void BFSUtil(int v, bool visitCheck[]) {
            visitCheck[v] = true;
            cout<<v<<" ";
            // q.push(v);

            for(list <int>::iterator i = l[v].begin(); i!=l[v].end(); i++){
                if(!visitCheck[*i]) BFSUtil(*i, visitCheck);
            }

        }
        void BFS(int v) {
            bool *visitCheck = new bool[numOfVertices];
            for(int i=0; i<numOfVertices; i++) visitCheck[i] = false;

            BFSUtil(v, visitCheck);
        }
};

int main() {                    //Time complexity: V+E (V = no. of vertices, E = no. of edges)
    Graph G1(5);                //Space complexity: O(V), since extra space of size V is required.

    G1.addEdge(0, 2);
    G1.addEdge(0, 3);
    G1.addEdge(1, 3);
    G1.addEdge(1, 4);
    G1.addEdge(2, 3);
    G1.addEdge(2, 4);
    G1.addEdge(2, 0);
    G1.addEdge(3, 0);
    G1.addEdge(3, 1);
    G1.addEdge(3, 2);
    G1.addEdge(3, 4);
    G1.addEdge(4, 1);
    G1.addEdge(4, 2);
    G1.addEdge(4, 3);

    G1.BFS(1);

    return 0;
}