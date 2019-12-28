class Solution {
public:
    int countFresh(vector<vector<int>>& grid){
        int total_fresh = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 1) total_fresh+= 1;
        return total_fresh;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int total_fresh = countFresh(grid);
        if(total_fresh == 0)
            return 0;
        
        queue<vector<int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        
        vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        
        while(!q.empty()){
            
            vector<int> parent = q.front(); q.pop();
            int r = parent[0];
            int c = parent[1];
            int dist = parent[2];
            
            for(int i = 0; i < 4; i++){
                int new_r = r + dir[i][0];
                int new_c = c + dir[i][1];
                
                if(0 <= new_r && new_r < grid.size() && 0 <= new_c && new_c < grid[0].size()){
                    if(grid[new_r][new_c] == 1 && !visited[new_r][new_c]){
                        visited[new_r][new_c] = true;
                        q.push({new_r, new_c, dist + 1});
                        total_fresh -= 1;
                        if(total_fresh == 0) return dist + 1;
                    }
                }
            }
        }
        
        return -1;
    }
};