class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = INT_MAX;
        int i = 0;
        int sum_so_far = 0;
        
        for(int j = 0; j < nums.size(); j++){
            sum_so_far += nums[j];
                while(sum_so_far >= s){
                    ans = min(ans, j - i + 1);
                    sum_so_far -= nums[i];
                    i++;
                }
        }
        ans = ans == INT_MAX ? 0 : ans ;
        return ans;
    }
};