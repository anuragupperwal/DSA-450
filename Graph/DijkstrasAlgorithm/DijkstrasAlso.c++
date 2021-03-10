#include<iostream>
#include<climits>
#include<map>

using namespace std;

map <int, map<int, int> > graph;

int inputGraph(int V, int E, int count) {
    if(count<E) {
        int u, v, wt;
        cin>>u>>v>>wt;
        if(u<V && v<V) {
            graph[u][v] = wt;
            graph[v][u] = wt;
        }
        return inputGraph( V, E, ++count);
    }
    return 0;
}

int findMinVertex(int V, bool visited[], int wt[]) {
    int minVertex = -1;
    for(int i=0; i<V; ++i) {
        if(( minVertex == -1 || wt[i] < wt[minVertex]) && !visited[i]) {
            minVertex = i;
        }
    }
    return minVertex;
}

void PrimsAlgo(int V, int E, int i) {
    int *wt = new int[V];
    int *parent = new int[V];
    bool *visited = new bool[V];

    for(int j=0; j<V; ++j) {
        visited[j] = false;
        wt[j] = INT_MAX;
    }

    //assigning the root vertex with with appropriate values.
    wt[i] = 0;
    parent[i] = -1;

    //main algorithm to identify the edge with least weight to traverse to.
    for(int j=0; j<V; ++j) {
        //to find the vertex with minimum weight.
        int minVertex = findMinVertex(V, visited, wt);
        visited[minVertex] = true;
        
        for(int k=0; k<V; ++k) {
            if(graph[minVertex][k] != 0 && !visited[k]){
                if(wt[k] > graph[minVertex][k] + wt[minVertex]) {
                    wt[k] = graph[minVertex][k] + wt[minVertex];
                    parent[k] = minVertex;
                }
            }
        }            
    } 

    //to print vertices of minimum spanning tree.
    for(int i=0; i<V; ++i) {
        cout<<endl<<i<<": "<<wt[i];
    }
}

int main() {
    int V, E;
    cin>>V>>E;

    //allocating matrix 0 for all the elements.
    for(int i=0; i<V; ++i) {
        for(int j=0; j<V; ++j) {
            graph[i][j] = 0;
        }
    }
    
    //Taking input for the graph.
    inputGraph(V, E, 0);

    //implementation of prim's algorithm
    PrimsAlgo(V, E, 2);

    return 0;
}