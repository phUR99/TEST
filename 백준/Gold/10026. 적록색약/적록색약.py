import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input().strip())

board = [input().strip() for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]

q = deque()


def oob(x):
    return x < 0 or x >= n


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

cnt = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            cnt += 1
            visited[i][j] = True
            q.append((i, j))
            while q:
                x, y = q.popleft()
                for dir in range(4):
                    nx = x + dx[dir]
                    ny = y + dy[dir]
                    if oob(nx) or oob(ny):
                        continue
                    if visited[nx][ny] or board[nx][ny] != board[i][j]:
                        continue
                    visited[nx][ny] = True
                    q.append((nx, ny))
print(cnt, end=" ")
cnt = 0
visited = [[False for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            cnt += 1
            visited[i][j] = True
            q.append((i, j))
            while q:
                x, y = q.popleft()
                for dir in range(4):
                    nx = x + dx[dir]
                    ny = y + dy[dir]
                    if oob(nx) or oob(ny):
                        continue
                    if visited[nx][ny]:
                        continue
                    # 연산자 우선순위
                    if board[i][j] in "RG" and board[nx][ny] != "B":
                        visited[nx][ny] = True
                        q.append((nx, ny))
                    if board[i][j] == "B" and board[nx][ny] == "B":
                        visited[nx][ny] = True
                        q.append((nx, ny))
print(cnt)
