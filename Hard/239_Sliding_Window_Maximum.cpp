#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     vector<int> ans;
        deque<int> dq;

        for(int i = 0; i < nums.size(); i++){
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i); // How dq.push() is amortized O(1) ?
            while(dq.front() <= i - k)
                dq.pop_front();

             if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

