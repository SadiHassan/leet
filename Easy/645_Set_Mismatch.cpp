/*
//Approach 7: Using XOR
//Read this solution later to have fun and interesting insights!!!

public class Solution {
    public int[] findErrorNums(int[] nums) {
        int xor = 0, xor0 = 0, xor1 = 0;
        for (int n: nums)
            xor ^= n;
        for (int i = 1; i <= nums.length; i++)
            xor ^= i;
        int rightmostbit = xor & ~(xor - 1);
        for (int n: nums) {
            if ((n & rightmostbit) != 0)
                xor1 ^= n;
            else
                xor0 ^= n;
        }
        for (int i = 1; i <= nums.length; i++) {
            if ((i & rightmostbit) != 0)
                xor1 ^= i;
            else
                xor0 ^= i;
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == xor0)
                return new int[]{xor0, xor1};
        }
        return new int[]{xor1, xor0};
    }
}

*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            if(i == nums.size() - 1) break;
            if(nums[i] == nums[i+1]){
                ans.push_back(nums[i]);
                sum = sum - nums[i];
            }
        }
        int n = nums.size();
        ans.push_back((n * (n + 1) / 2) - sum);
        return ans;
    }
};