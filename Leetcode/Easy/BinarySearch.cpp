#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int BS(vector<int>& nums, int target, int start, int end) {
        if(end>=start) {
            int mid = start + (end - start)/2;
            if(nums[mid] == target) return (mid);
            else if(target > nums[mid]) return BS(nums, target, mid+1, end);
            else if(target < nums[mid]) return BS(nums, target, start, mid-1);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return BS(nums, target, 0, nums.size());
    }
};

int main() {
    Solution s;
    int target = 9, j;
    vector <int> nums;
    
    for(int i=0; i<6; ++i) {
        cin>>j;
        nums.push_back(j);
    }
    cout<<s.search(nums, target);
}
//  = {-1,0,3,5,9,12}