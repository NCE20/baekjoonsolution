import sys
sys.setrecursionlimit(10000)

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def dfs(row, col):
    visited[row][col] = True
    for k in range(4):
        nx = col + dx[k]
        ny = row + dy[k]

        if 0 <= nx < n and 0 <= ny < n and not visited[ny][nx] and grid[ny][nx] == grid[row][col]:
            dfs(ny, nx)


n = int(input())

grid = [list(input()) for _ in range(n)]
visited = [[False] * n for _ in range(n)]

cnt1 = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            dfs(i, j)
            cnt1 += 1

for i in range(n):
    for j in range(n):
        if grid[i][j] == 'G':
            grid[i][j] = 'R'

visited = [[False] * n for _ in range(n)]
cnt2 = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            dfs(i, j)
            cnt2 += 1

print(cnt1, cnt2)
