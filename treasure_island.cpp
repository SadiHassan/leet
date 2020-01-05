#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// BFS
int minStepsBFS(vector<vector<char>>& island) {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = island.size(), n = island[0].size();

    queue<pair<int, int>> q;
    q.push(std::pair<int, int>(0, 0)); island[0][0] = 'D';

    int steps = 1;
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            auto pos = q.front();
            q.pop();
            for (auto dir: dirs) {
                int nx = pos.first + dir[0];
                int ny = pos.second + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || island[nx][ny] == 'D') continue;
                if (island[nx][ny] == 'X') return steps;
                q.push(pair<int,int>(nx, ny));
                island[nx][ny] = 'D';
            } 
        }
        
        ++steps;
    }

    return -1;
}