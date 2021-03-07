#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph {
        list <int> *l;
        int numOfVertices;
        stack <int> s;
    
    public: 
        Graph(int v) {
            this->numOfVertices = v;
            l = new list <int>[numOfVertices];
        }
        void addEdge(int u, int v) {
            l[u].push_back(v);
        }

        int check(int i, int visitCheck[]) {
            int res = 0;
            if(s.empty()) {
                s.push(i);
                visitCheck[i] = 0;
            }
            for(list<int>::iterator itr = l[i].begin(); itr!=l[i].end(); itr++) {
                if(visitCheck[*itr] == -1) {
                    visitCheck[*itr] = 0;
                    s.push(*itr);
                    res = check(*itr, visitCheck);
                }
                else if(visitCheck[*itr] == 0) {
                    res = 1;
                }

                if(res == 1) break;
            }

            cout<<s.top()<<" ";
            visitCheck[s.top()] = 1;
            s.pop();
            return res; 
        }
        void cyclicCheck() {
            int *visitCheck = new int[numOfVertices], res;
            for(int i=0; i<numOfVertices; ++i) visitCheck[i] = -1;

            for(int i=0; i<numOfVertices; ++i) {
                res = check(i, visitCheck);
                if(res == 1) break;
            }

            if(res == 1) cout<<"\n\nIt is a cyclic graph.";
            else cout<<"It is not a cyclic graph.";
        }
};

int main() {
    Graph g1(4);

    g1.addEdge(0, 3);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);

    g1.cyclicCheck();

    return 0;
}
 