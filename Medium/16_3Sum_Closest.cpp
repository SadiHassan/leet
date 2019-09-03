class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int diff_min = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                
                if(diff < diff_min){
                    diff_min = diff;
                    ans = sum;
                }
                if(sum == target)
                    return sum;
                else if(sum > target)
                    k--;
                else{
                    j++;
                }
                
            }
        }
        
        return ans;
    }
};