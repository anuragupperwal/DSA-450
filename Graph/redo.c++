#include<iostream>
#include<map>

using namespace std;

class mazeMatrix {
        map <int, map<int, int> > maze, res;
        map <int, map< int, bool> >visited;
        int size;
    public:
        mazeMatrix(int v) {
            size = v;
            for(int i=0; i<size; ++i) {
                for(int j=0; j<size; ++j) {
                   maze[i][j] = 0;
                }
            }
            for(int i=0; i<size; ++i) {
                for(int j=0; j<size; ++j) {
                    visited[i][j] = false;
                }
            }
        }

        void addPath(int i, int j) {
            maze[i][j] = 1;
        }
        void print() {
            for(int i=0; i<size; ++i) {
                for(int j=0; j<size; ++j) {
                    cout<<res[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        bool isSafe(int i, int j) {
            if(i<size && j<size && i>=0 && j>=0 && maze[i][j]==1 && visited[i][j] == false) return true;
            return false;
        }
        bool ratInTheMaze(int i, int j) {
            if(i==size-1 && j==size-1) {
                res[i][j] = 1;
                return true;
            }
            if(isSafe(i, j)) {
                visited[i][j] = true;
                res[i][j] = 1;
                if(isSafe(i, j+1)) {
                    if(ratInTheMaze(i, j+1)) {
                        return true;
                    }
                }
                if(isSafe(i+1, j)) {
                    if(ratInTheMaze(i+1, j)) {
                        return true;
                    }
                }
                if(isSafe(i, j-1)) {
                    if(ratInTheMaze(i, j-1)) {
                        return true;
                    }
                }
                if(isSafe(i-1, j)) {
                    if(ratInTheMaze(i-1, j)) {
                        return true;
                    }
                }

                //backtracking
                res[i][j] = 0;
                visited[i][j] = false;
            }
            return false;
        }
};

int main() {
    mazeMatrix m1(5);

    // m1.addPath(0, 0);
    // m1.addPath(0, 2);
    // m1.addPath(0, 3);
    // m1.addPath(0, 4);
    // m1.addPath(1, 0);
    // m1.addPath(1, 1);
    // m1.addPath(1, 2);
    // m1.addPath(1, 4);
    // m1.addPath(2, 2);
    // // m1.addPath(2, 3);
    // m1.addPath(2, 4);
    // m1.addPath(3, 2);
    // // m1.addPath(3, 3);
    // m1.addPath(3, 4);
    // m1.addPath(4, 2);
    // m1.addPath(4, 3);
    // m1.addPath(4, 4);

    m1.addPath(0, 0);
    m1.addPath(0, 1);
    m1.addPath(0, 2);
    m1.addPath(0, 4);
    m1.addPath(1, 2);
    m1.addPath(1, 3);
    // m1.addPath(1, 4);
    m1.addPath(2, 3);
    m1.addPath(2, 4);
    m1.addPath(3, 1);
    m1.addPath(3, 2);
    m1.addPath(3, 3);
    m1.addPath(4, 1);
    m1.addPath(4, 2);
    m1.addPath(4, 3);
    m1.addPath(4, 4);

    m1.ratInTheMaze(0, 0);

    m1.print();

    return 0;
}