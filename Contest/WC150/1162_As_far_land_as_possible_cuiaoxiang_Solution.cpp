const int N = 100 + 10;
const int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dp[N][N];
typedef pair<int, int> ii;

class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        queue<ii> Q;
        memset(dp, 255, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) {
                    Q.push({i, j});
                    dp[i][j] = 0;
                }
            }
        }
        while (!Q.empty()) {
            int x = Q.front().first, y = Q.front().second;
            Q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0];
                int ny = y + d[k][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dp[nx][ny] >= 0) continue;
                dp[nx][ny] = dp[x][y] + 1;
                Q.push({nx, ny});
            }
        }
        int ret = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dp[i][j]) ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};