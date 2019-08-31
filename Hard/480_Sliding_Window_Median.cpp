//TLE -- Work In Progress
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        if(nums.size() == 0 || k == 0) return ans;
        for(int i = 0; i + k <= nums.size(); i++){
            vector<double> arr;
            for(int j = i; j < (i + k); j++){
                int x = (double) nums[j];
                arr.push_back(x);
            }
            sort(arr.begin(), arr.end());
            //for(int kk = 0; kk < arr.size(); kk++) cout << arr[kk] << " "; cout << endl;
            if(k % 2 == 0)
                ans.push_back( (arr[k/2] + arr[k/2 - 1]) / 2.0 );
            else
                ans.push_back(arr[k/2]);
        }
        return ans;
      
    }
};