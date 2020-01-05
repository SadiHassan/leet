import collections
import sys

def treasure(matrix):
    res = sys.maxsize
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 'S':
                temp = bfs(matrix, i, j)
                res = min(res, temp)
    return res

def bfs(matrix, i, j):
    queue = collections.deque()
    queue.append((i, j, 0))
    visited = set()
    directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    while queue:
        x, y, distance = queue.popleft()
        if matrix[x][y] == 'X':
            return distance
        for dirs in directions:
            n_x = x + dirs[0]
            n_y = y + dirs[1]
            if 0 <= n_x < len(matrix) and 0 <= n_y < len(matrix[0]) and matrix[n_x][n_y] != 'D':
                queue.append((n_x, n_y, distance + 1))
                visited.add((n_x, n_y))
    return sys.maxsize

print(treasure([
    ['S', 'O', 'O', 'S', 'S'],
    ['D', 'O', 'D', 'O', 'D'],
    ['O', 'O', 'O', 'O', 'X'],
    ['X', 'D', 'D', 'O', 'O'],
    ['X', 'D', 'D', 'D', 'O']
    ]
))