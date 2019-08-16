class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        
        if(intervals.size() == 0)
            return ans;
        
        int START = 0;
        int END = 1;
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b)
        {
            return a[0] < b[0];
        });
        
        
        
        ans.push_back({intervals[0][START], intervals[0][END]});
        int ind = 0;
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][START] > ans[ind][END]){
                ind++;
                ans.push_back({intervals[i][START], intervals[i][END]});
            }
            else{
                ans[ind][END] = max(ans[ind][END], intervals[i][END]);
            }
        }
        
        return ans;
    }
};