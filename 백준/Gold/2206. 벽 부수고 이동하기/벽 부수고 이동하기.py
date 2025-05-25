import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().strip().split())

board = [input().strip() for _ in range(n)]
dist = [[[-1 for _ in range(2)] for _ in range(m)] for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

q = deque()

q.append((0, 0, 0))
dist[0][0][0] = 1


def oob(x, y):
    return x < 0 or x >= n or y < 0 or y >= m


while q:
    hx, hy, ht = q.popleft()

    for dir in range(4):
        nx = dx[dir] + hx
        ny = dy[dir] + hy
        if oob(nx, ny):
            continue
        if board[nx][ny] == "1" and ht == 1:
            continue
        if board[nx][ny] == "1":
            if dist[nx][ny][ht + 1] != -1:
                continue
            q.append((nx, ny, ht + 1))
            dist[nx][ny][ht + 1] = dist[hx][hy][ht] + 1
        else:
            if dist[nx][ny][ht] != -1:
                continue
            q.append((nx, ny, ht))
            dist[nx][ny][ht] = dist[hx][hy][ht] + 1

if dist[n - 1][m - 1][0] == -1 and dist[n - 1][m - 1][1] == -1:
    print(-1)
else:
    if dist[n - 1][m - 1][0] == -1:
        dist[n - 1][m - 1][0] = 987654321
    if dist[n - 1][m - 1][1] == -1:
        dist[n - 1][m - 1][1] = 987654321
    print(min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]))
