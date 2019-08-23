class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		bool has0 = false, has1 = false;
		int n = grid.size(), i, j, k, x, y, xx, yy, ans;
		int v[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
		
		queue<pair<int, int>> q;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (grid[i][j] == 0) has0 = true;
				if (grid[i][j] == 1) {
					has1 = true;
					q.push({ i,j });
				}
			}
		}

		if (!has0) return - 1;
		if (!has1) return - 1;

		ans = 1;
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			ans = max(ans, grid[x][y]);

			for (i = 0; i < 4; i++) {
				xx = x + v[i][0];
				yy = y + v[i][1];
				if ((xx >= 0) && (xx < n) && (yy >= 0) && (yy < n) && (grid[xx][yy] == 0)) {
					grid[xx][yy] = grid[x][y] + 1;
					q.push({ xx, yy });
				}
			}
		}

		return ans - 1;
	}
};