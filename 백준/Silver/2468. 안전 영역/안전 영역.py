import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input().strip())

board = [list(map(int, input().strip().split())) for _ in range(n)]

M = 0
for i in range(n):
    M = max(M, max(board[i]))

cnt = 0


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


for k in range(M + 1):
    visited = [[0 for _ in range(n)] for _ in range(n)]
    tmp = 0
    for i in range(n):
        for j in range(n):
            if not visited[i][j] and board[i][j] > k:
                tmp += 1

                def bfs(i, j, iter):

                    q = deque()
                    q.append((i, j))
                    visited[i][j] = 1

                    while q:
                        x, y = q.popleft()
                        for dir in range(4):
                            nx = dx[dir] + x
                            ny = dy[dir] + y
                            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                                continue
                            if visited[nx][ny] or board[nx][ny] <= iter:
                                continue
                            visited[nx][ny] = 1
                            q.append((nx, ny))

                bfs(i, j, k)
    cnt = max(cnt, tmp)

print(cnt)
