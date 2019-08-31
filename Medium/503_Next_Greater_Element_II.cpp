//Work in progress
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int i = 0;
        int j = 0;
        while(nums[i] != -1){
            if(s.empty())
                s.push(i);
            while(!s.empty() && nums[s.top()] < nums[i]){
                nums[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
            i = (i + 1) % nums.size();
            if(i == 0) j++;
            if(i == 0 && j > 1) break;
        }
        
        return nums;
    }
};