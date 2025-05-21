import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

m, n, k = map(int, input().strip().split())
board = [[0 for _ in range(m)] for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]

for _ in range(k):
    lx, ly, rx, ry = map(int, input().strip().split())
    for i in range(lx, rx):
        for j in range(ly, ry):
            board[i][j] = 1

ret = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(n):
    for j in range(m):
        if not visited[i][j] and not board[i][j]:

            def bfs(x, y):
                q = deque()
                visited[x][y] = 1
                q.append((x, y))
                cnt = 1
                while q:
                    hx, hy = q.popleft()
                    for dir in range(4):
                        nx = hx + dx[dir]
                        ny = hy + dy[dir]
                        if nx < 0 or nx >= n or ny < 0 or ny >= m:
                            continue
                        if board[nx][ny] or visited[nx][ny]:
                            continue
                        cnt += 1
                        q.append((nx, ny))
                        visited[nx][ny] = 1
                ret.append(cnt)

            bfs(i, j)

print(len(ret))
ret.sort()
print(*ret)
