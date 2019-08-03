class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        int l = 0, r = 0;
        vector<int> ans;
        
        while(l < len1 && r < len2){
            int left = nums1[l];
            int right = nums2[r];
            
            if(left == right){
                if(ans.size() > 0){
                    int ind = ans.size() - 1;
                    if(left != ans[ind])
                        ans.push_back(left);
                }
                else ans.push_back(left);
                
                l++;
                r++;
            }
            if(left < right){
                l++;
            }
            else if(right < left){
                r++;
            }
        }
        
        return ans;
    }
};