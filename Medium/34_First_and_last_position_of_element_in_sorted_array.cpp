class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        int left = 0;
        int right = nums.size() - 1;
        
        int ind = -1;
        
        //Fidn the first occurance of target
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                ind = mid;
                right = mid - 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        ans.push_back(ind);
        
        //Fidn the last occurance of target
        left = 0;
        right = nums.size() - 1;
        ind = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                ind = mid;
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        ans.push_back(ind);
        return ans;    
    }
};