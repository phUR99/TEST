import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
m, n = map(int, input().strip().split())

board = [list(map(int, input().strip().split())) for _ in range(n)]
dist = [[-1 for _ in range(m)] for _ in range(n)]

q = deque()
for i in range(n):
    for j in range(m):
        if board[i][j] == 1:
            q.append((i, j))
            dist[i][j] = 0


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
while q:
    x, y = q.popleft()
    for dir in range(4):
        nx = dx[dir] + x
        ny = dy[dir] + y
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if dist[nx][ny] != -1 or board[nx][ny] == -1:
            continue
        dist[nx][ny] = dist[x][y] + 1
        q.append((nx, ny))

ret = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == -1:
            continue
        ret = max(ret, dist[i][j])
        if dist[i][j] == -1:
            print(-1)
            exit(0)

print(ret)
