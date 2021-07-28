#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph {
        int numOfVertices;
        list <int> *l;
        stack <int> s;

    public:
        Graph(int vertex){
            this->numOfVertices = vertex;
            l = new list<int>[numOfVertices];
        }    
        void addEdge(int a, int b){
            l[a].push_back(b);
        }
        int sort(int x, bool visitCheck[]) {
            visitCheck[x] = true;
            for(list <int>::iterator i=l[x].begin(); i!=l[x].end(); i++) {
                if(visitCheck[*i] == false) {
                    sort(*i, visitCheck);
                }
            }
            
            s.push(x);           
            return 0;
        }

        void topologicalSort(){
            bool *visitCheck = new bool[numOfVertices];
            for(int i=0; i<numOfVertices; i++) visitCheck[i] = false;

            for(int i=0; i<numOfVertices; ++i)   if(visitCheck[i] == false) sort(i, visitCheck); 

            while(!s.empty() ) {
                cout<<"\n"<<s.top();
                s.pop();
            }
        }
};


int main() {
    Graph g1(6);
    g1.addEdge(4, 0);
    g1.addEdge(4, 1);
    g1.addEdge(3, 1);
    g1.addEdge(2, 3);
    g1.addEdge(5, 0);
    g1.addEdge(5, 2);

    cout<<"Topological sort: ";
    g1.topologicalSort();

    return 0;
}