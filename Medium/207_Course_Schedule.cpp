class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        vector<int> degree(numCourses + 1, 0);
        vector<vector<int>> graph(numCourses + 1);
        map<int, bool> m;
        int total_node = 0;
        for(auto node: prerequisites){
            int boss = node[1];
            int challi = node[0];
            degree[challi] += 1;
            graph[boss].push_back(challi);
            if(m.find(boss) == m.end()){
                m[boss] = true;
                total_node += 1;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++)
            if(degree[i] == 0){
                q.push(i); 
                
            }
        
        //cout << graph.size() << endl;
        total_node -= q.size();
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int i = 0; i < graph[cur].size(); i++){
                int child = graph[cur][i];
                degree[child] -= 1;
                if(degree[child] == 0){
                    //numCourses -= 1;
                    total_node -= 1;
                    q.push(child);
                }
            }
        }
        //cout << len << endl;
        if(total_node > 0) return false;
        return true;
    }
};