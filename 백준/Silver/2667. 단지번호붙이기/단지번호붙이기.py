import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input().strip())

board = [input().strip() for _ in range(n)]
visited = [[0 for _ in range(n)] for _ in range(n)]


ret = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(n):
    for j in range(n):
        if not visited[i][j] and board[i][j] == "1":

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
                        if nx < 0 or nx >= n or ny < 0 or ny >= n:
                            continue
                        if board[nx][ny] == "0" or visited[nx][ny]:
                            continue
                        cnt += 1
                        q.append((nx, ny))
                        visited[nx][ny] = 1
                ret.append(cnt)

            bfs(i, j)
print(len(ret))
ret.sort()
print(*ret, sep="\n")
