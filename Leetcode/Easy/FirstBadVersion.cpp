#include<iostream>

using namespace std;

class Solution {
public:
    int bs(int start, int end) {
        int mid = start + (end - start)/2;
        bool badCheck = isBadVersion(mid);
        if(badCheck == true) {
            if(isBadVersion(mid-1) == false) return (mid-1);
            else return bs(start, mid-1);
        }
        else return bs(mid+1, end);
    }

    int firstBadVersion(int n) {
        int start  = 1, end = n;    
        bs(start, end);
    }
};

int main() {


    return 0;
}