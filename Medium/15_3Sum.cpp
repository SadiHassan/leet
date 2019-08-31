class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        if(nums[0] == 0 && nums[nums.size()-1] == 0 && nums.size() >= 3)
            { ans.push_back({0,0,0}); return ans;}
        
        for(int i = 0; i < nums.size(); i++){
            
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] > 0) k--;
                else if(nums[i] + nums[j] + nums[k] < 0) j++;
                else {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        k--; j++;
                }
            }
        }
        
        if(ans.size() <= 1) return ans;
        
        vector<vector<int>> ans_distinct;
        //sort(ans[0].begin(), ans[0].end());
        ans_distinct.push_back(ans[0]);
        sort(ans.begin(), ans.end());
        for(int i = 1; i < ans.size(); i++){
            
            if(ans[i][0] == ans[i-1][0] && 
               ans[i][1] == ans[i-1][1] && 
               ans[i][2] == ans[i-1][2])
                continue;
            else ans_distinct.push_back(ans[i]);
        }
        
        return ans_distinct;
    }
};