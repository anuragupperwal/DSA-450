#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph {
        list <int> *l;
        int numOfVertices;
        queue <int> q;
    
    public: 
        Graph(int v) {
            this->numOfVertices = v;
            l = new list <int>[numOfVertices];
        }
        void addEdge(int u, int v) {
            l[u].push_back(v);
            l[v].push_back(u);
        }
        int check(int i, int visitCheck[]) {
            int res = 0;
            if(q.empty()) {
                q.push(i);
                visitCheck[i] = 0;
            }
            for(list<int>::iterator itr = l[i].begin(); itr!=l[i].end(); itr++) {
                if(visitCheck[*itr] == -1) {
                    q.push(*itr);
                    visitCheck[*itr] = 0;
                }
                else if(visitCheck[*itr] == 0) {
                    res = 1;
                }
            }
            
            visitCheck[i] = 1;
            q.pop();
            if(!q.empty()) {
                // cout<<q.front()<<" ";
                i = q.front();
            } 
            if(res == 1) return 1;
            else if(res == 0 && !q.empty())  res = check(i, visitCheck);
            return res;
        }
        void cyclicCheck() {
            int *visitCheck = new int[numOfVertices], res;
            for(int i=0; i<numOfVertices; i++) visitCheck[i] = -1;

            for(int i=0; i<numOfVertices; i++) {
                if(visitCheck[i] == -1) res = check(i, visitCheck);
            }
            if(res == 1) cout<<"Its a cyclic graph.";
            else cout<<"Not a cyclic graph";

        }
};


int main() {

    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(3, 4);

    g1.cyclicCheck();
    return 0;
}