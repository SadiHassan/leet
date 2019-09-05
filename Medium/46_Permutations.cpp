class Solution {
public:
    vector<vector<int>> ans;
    vector<int> used;
    void rec(vector<int>& nums, vector<int>& arr, int total, vector<int>& used){
        if(total == nums.size()){
            ans.push_back(arr);
            return;
        }
        //cout << cur_index << endl;
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            used[i] = 1;
            arr.push_back(nums[i]);
            rec(nums, arr, total + 1, used);
            arr.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> arr;
        for(int i = 0; i < nums.size(); i++) used.push_back(0);
        rec(nums, arr, 0, used);
        return ans;
    }
};