class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        if(numCourses == 0) return ans;
        if(prerequisites.size() == 0){
            for(int i = 0; i < numCourses; i++) ans.push_back(i);
            return ans;
        }
        vector<vector<int>> arr(numCourses + 1);
        vector<int> degree(numCourses + 1);
        
        for(int i = 0; i < prerequisites.size(); i++){
        
            int challi = prerequisites[i][0];
            int boss = prerequisites[i][1];
        
            arr[boss].push_back(challi);
            degree[challi] += 1;
        }
        
        int N = numCourses;
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            if(degree[cur] == 0){
                N -= 1;
                ans.push_back(cur);
                for(int i = 0; i < arr[cur].size(); i++){
                    degree[ arr[cur][i] ] -= 1;
                    if(degree[ arr[cur][i] ] == 0) q.push(arr[cur][i]);
                }
            }
            
        }//end while-q
        vector<int> t;
        if(N > 0) return t;
        return ans;
    }
};