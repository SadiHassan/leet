class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0) return nums1;
        
        map<int, int> m;
        stack<int> s;
        
        for(int i = 0; i < nums2.size(); i++){
            if(s.empty())
                s.push(nums2[i]);
            while(!s.empty() && s.top() < nums2[i]){
                m[s.top()] = nums2[i];
                s.pop();
            }
            
            //if(s.top() > nums2[i])
            s.push(nums2[i]);
        }
        
        for(int i = 0; i < nums1.size(); i++)
            nums1[i] = m.find(nums1[i]) == m.end() ? -1 : m[nums1[i]];
        
        return nums1;
    }
};