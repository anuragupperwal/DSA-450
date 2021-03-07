#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

class Graph {

        int numOfVertices;
        list <int> *l;
    public:
        Graph(int x) {
            this->numOfVertices = x;
            l = new list<int>[numOfVertices];
        }
        void inputGraph(int a, int b) {
            l[a].push_back(b);
            l[b].push_back(a);
        }
        void printGraph() {
            for(int i=0; i<numOfVertices; ++i) {
                cout<<"Vertex "<<i<<": ";
                for(list <int>::iterator it=l[i].begin(); it!=l[i].end(); it++) {
                    cout<<*it<<" ";
                }
                cout<<endl;
            } 

        }
};


int main() {
    Graph G1(5);

    G1.inputGraph(0, 1);
    G1.inputGraph(0, 3);
    G1.inputGraph(1, 3);
    G1.inputGraph(1, 2);
    G1.inputGraph(2, 3);
    G1.inputGraph(2, 4);
    G1.inputGraph(3, 4);

    G1.printGraph();


    return 0;
}