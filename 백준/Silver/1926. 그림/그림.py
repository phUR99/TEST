import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().strip().split())
board = [list(map(int, input().strip().split())) for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(x, y):
    visited[x][y] = 1
    cnt = 1
    q = deque()
    q.append((x, y))
    while q:
        hx, hy = q.popleft()
        for i in range(4):
            nx = hx + dx[i]
            ny = hy + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if visited[nx][ny] or not board[nx][ny]:
                continue
            visited[nx][ny] = 1
            cnt += 1
            q.append((nx, ny))
    return cnt


cnt = 0
ret = 0
for i in range(n):
    for j in range(m):
        if board[i][j] and not visited[i][j]:
            cnt += 1
            ret = max(ret, bfs(i, j))
print(cnt)
print(ret)
