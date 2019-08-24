class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        
        int ans = 0;
        while(!pq.empty() && k > 0){
            if(k == 1) ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};