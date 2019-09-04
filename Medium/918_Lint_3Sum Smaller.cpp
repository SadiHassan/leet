class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        // Write your code here
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target){
                   //cout<< "i: " << i << " j: " << j << " k: " << k <<endl;
                   ans += (k - j);
                   j++;
                }
                else if(sum >= target) k--;
            }//end while
        }
    
        return ans;
    }
};