#include<iostream>
#include<map>
#include<climits>

using namespace std;

class Graph {
        map <int, map<int, int> > graph;
        int numOfVertices;
        int *wt;
    public:
        Graph(int v) {
            numOfVertices = v;
            wt = new int[numOfVertices];
        }
        void addEdge(int u, int v, int w) {
            graph[u][v] = w;
        }

        //recursive function to execute relaxation of edges.
        int Relaxation(int u, int v) {
            if(v < numOfVertices) {
                if(graph[u][v] != 0) {
                    if( (wt[u] + graph[u][v]) < wt[v] ) {
                        wt[v] = wt[u] + graph[u][v];
                    }
                }
                return Relaxation(u, ++v);
            }
            return 0;
        }

        void BellmanFordAlgo(int x) {
            //creating the weight array with infinite value.
            for(int i=0; i<numOfVertices; ++i) wt[i] = INT_MAX;
            //assigning the source weight as 0.
            wt[x] = 0;
            
            //iterating over each vertex of the graph 
            for(int k=0; k<numOfVertices-1; ++k){
                for(int i=0; i<numOfVertices-1; ++i) {
                    //calling the recursive function to relax the edges.
                    Relaxation(i, 0);
                }
            }

            //printing the vertices with minimum distance from the source.
            for(int i=0; i<numOfVertices; ++i) cout<<i<<" "<<wt[i]<<endl;
        }
};

int main() {
    Graph g1(7);

    //inserting the edges of the graph
    g1.addEdge(0, 1, 6);
    g1.addEdge(0, 2 ,5);
    g1.addEdge(0, 3, 5);
    g1.addEdge(1, 4, -1);
    g1.addEdge(2, 1, -2);
    g1.addEdge(2, 4, 1);
    g1.addEdge(3, 2, -2);
    g1.addEdge(3, 5, -1);
    g1.addEdge(4, 6, 3);
    g1.addEdge(5, 6, 3);

    //calling of the main algorithm
    g1.BellmanFordAlgo(0);

    return 0;
}