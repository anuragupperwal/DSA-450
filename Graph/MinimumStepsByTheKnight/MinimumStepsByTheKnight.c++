#include<iostream>
#include<map>
#include</Users/anuragupperwal/stdc++.h>

using namespace std;

class knightMove {
        int size;
        map<int, map<int, int> > chessBoard;
        queue <pair< int, int> > q;
        pair <int, int> path;
    public:
        knightMove(int s) {
            size = s;
            for(int i=1; i<=size; ++i) {
                for(int j=1; j<=size; ++j) {
                    chessBoard[i][j] = 0;
                }
            }
        }
        bool isSafe(int i, int j) {
            if(i<=size && i>0 && j<=size && j>0 && chessBoard[i][j] ==0) return true;
            return false;
        }
        void addToStack(int i, int j, int val) {
            path.first = i;
            path.second = j;
            q.push(path);
            chessBoard[i][j] = val + 1;
        }
        bool findPath(int sX, int sY, int dX, int dY, int val) {
            val = chessBoard[sX][sY];

            if(isSafe(sX+1, sY+2)) {
                addToStack(sX+1, sY+2, val);
            }
            if(isSafe(sX-1, sY+2)) {
                addToStack(sX-1, sY+2, val);
            }
            if(isSafe(sX+1, sY-2)) {
                addToStack(sX+1, sY-2, val);
            }
            if(isSafe(sX-1, sY-2)) {
                addToStack(sX-1, sY-2, val);
            }
            if(isSafe(sX+2, sY+1)) {
                addToStack(sX+2, sY+1, val);
            }
            if(isSafe(sX+2, sY-1)) {
                addToStack(sX+2, sY-1, val);
            }
            if(isSafe(sX-2, sY+1)) {
                addToStack(sX-2, sY+1, val);
            }
            if(isSafe(sX+2, sY-1)) {
                addToStack(sX+2, sY-1, val);
            }
            int a, b;
            while(!q.empty()) {
                a = q.front().first;
                b = q.front().second;
                q.pop();
                findPath(a, b, dX, dY, chessBoard[a][b]);
            }
            if(sX == dX && sY == dY) {
                cout<<"Found destination at: "<<sX<<", "<<sY;
                cout<<"\nNumber of steps taken: "<<chessBoard[dX][dY];
                return true;
            }
            else {
                return false;
            }
        }   
        void showNumOfSteps() {
        }
};


int main() {
    knightMove k(6);

    k.findPath(2, 4, 6, 1, 0);

    return 0;
}