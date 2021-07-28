#include<iostream>
#include<map>
#include<climits>

using namespace std;

class Graph {
        int numOfVertices;
        map <int, map<int, int> > graph;
    public:
        Graph(int v) {
            numOfVertices = v;
            for(int i=0; i<numOfVertices; ++i) {
                for(int j=0; j<numOfVertices; ++j) {
                    graph[i][j] = INT_MAX;
                }
            }
        }
        //to add an edge in the graph
        void addEdge(int u, int v, int w) {
            graph[u][v] = w;
        }
        void FloydWarshallAlgorithm() {
            //assigning 0 to all non-connected diagonal edges
            for(int i=0; i<numOfVertices; ++i) {
                if(graph[i][i] == INT_MAX) graph[i][i] = 0;
            }
            
            //iteration over the graph to find out the shortest path 
            for(int x=0; x<numOfVertices; ++x) {
                for(int i=0; i<numOfVertices; ++i) {
                    for(int j=0; j<numOfVertices; ++j) {
                        if(i!=x) {
                            if(j!=x){
                                if(graph[i][x] == INT_MAX || graph[x][j] == INT_MAX) {
                                    if(graph[i][j] > INT_MAX) graph[i][j] = graph[i][x] + graph[x][j];
                                }
                                else if(graph[i][j] > graph[i][x] + graph[x][j]) {
                                    graph[i][j] = graph[i][x] + graph[x][j];
                                }
                            }
                        }
                    }
                }
            }

            //to print shortest path from all the edges
            for(int i=0; i<numOfVertices; ++ i) {
                for(int j=0; j<numOfVertices; ++j) {
                    cout<<i<<" -> "<<j<<" = "<<graph[i][j]<<endl;
                }
                cout<<endl;
            }
        }
};

int main() {
    Graph g1(4);

    g1.addEdge(0, 1, 9);
    g1.addEdge(0, 2, -4);
    g1.addEdge(1, 0, 6);
    g1.addEdge(1, 3, -2);
    g1.addEdge(2, 1, 5);
    g1.addEdge(3, 2, 1);

    // g1.addEdge(0, 4, -1);
    // g1.addEdge(1, 0, 1);
    // g1.addEdge(1, 3, 2);
    // g1.addEdge(2, 1, 2);
    // g1.addEdge(2, 5, -8);
    // g1.addEdge(3, 0, -4);
    // g1.addEdge(3, 4, 3);
    // g1.addEdge(4, 1, 7);
    // g1.addEdge(5, 2, 10);
    // g1.addEdge(5, 1, 5);

    //calling the main Floyd Warshall function
    g1.FloydWarshallAlgorithm(); 

    return 0;
}