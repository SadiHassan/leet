class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else
                m[nums[i]] += 1;
        }
        
        
        priority_queue<pair<int, int>> pq;
        
        for(map<int, int>::iterator it = m.begin() ; it != m.end(); ++it){
            pq.push(make_pair(it->second, it->first)); //it->first = number; it->second = frequency
        }
        
        vector<int> ans;
        
        while(!pq.empty() && k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};