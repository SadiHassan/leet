class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int> > V(n, vector<int>(n, 0));
        int i = 0, j = 0, count = 1;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int curr_dir = 0;
        while(count <= n*n) {
            V[i][j] = count;
            count++;
            int nx = i+dir[curr_dir][0], ny = j+dir[curr_dir][1];
            if((nx >= n || nx < 0) || (ny >= n || ny < 0) || V[nx][ny] != 0)
                curr_dir = (curr_dir+1)%4;
            i = i+dir[curr_dir][0]; j = j+dir[curr_dir][1];
        }
        return V;
    }
};