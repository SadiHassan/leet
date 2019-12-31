//Version-1: Worked faster in leetcode
class Solution {
public:
    
    void rec(vector<vector<char>>& grid, int r, int c, int height, int width){
        grid[r][c] = '2';
        if(r-1>=0){ if(grid[r-1][c]=='1') rec(grid, r-1, c, height, width); }
        if(r+1<height){ if(grid[r+1][c]=='1') rec(grid, r+1, c, height, width); }
        if(c-1>=0){ if(grid[r][c-1]=='1') rec(grid, r, c-1, height, width); }
        if(c+1<width){ if(grid[r][c+1]=='1') rec(grid, r, c+1, height, width); }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        if(height==0) return 0;
        int width = grid[0].size();
        int noIslands = 0;
        for(int r=0; r<height; r++){
            for(int c=0; c<width; c++){
                if(grid[r][c]=='1'){
                    noIslands++;
                    rec(grid, r, c, height, width);
                }
            }
        }
        return noIslands;
    }
};

//Version-1: Easier to handle directions
class Solution {
public:
    
    void rec(vector<vector<char>>& grid, int r, int c){
        
        grid[r][c] = '.';
        
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int R = grid.size();
        int C = grid[0].size();
        
        for(int i = 0; i < 4; i++){
            int rr = r + dir[i][0];
            int cc = c + dir[i][1];
            if(0 <= rr && rr < R && 0 <= cc && cc < C ){
                if(grid[rr][cc] == '1') rec(grid, rr, cc);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int num_clusters = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    num_clusters++;
                    rec(grid, i, j);
                }
            }
        }
        
        return num_clusters;
    }
};
