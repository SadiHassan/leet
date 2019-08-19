class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if(tree.size() == 0) return 0;
        map<int, int> m;
        int ans = 0;
        
        int i = 0;
        
        for(int j = 0; j < tree.size(); j++){
            
            if(m.find(tree[j]) == m.end()){ //new element
                m[tree[j]] = 1;
            }
            else m[tree[j]] += 1;
            
            while(m.size() > 2){
                m[tree[i]] -= 1;
                if(m[tree[i]] == 0){
                    m.erase(tree[i]);
                }
                i++;
            }
            
            ans = max(j - i + 1, ans);
        }
        
        
        return ans;
        
    }
};