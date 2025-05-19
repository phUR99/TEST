import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n, m = map(int, input().strip().split())
board = [input().strip() for _ in range(n)]


def bfs():
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    dist = [[-1 for _ in range(m)] for _ in range(n)]
    dist[0][0] = 1
    q = deque()
    q.append((0, 0))
    while q:
        x, y = q.popleft()
        for dir in range(4):
            nx = dx[dir] + x
            ny = dy[dir] + y
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if board[nx][ny] == "0" or dist[nx][ny] != -1:
                continue
            dist[nx][ny] = dist[x][y] + 1
            q.append((nx, ny))
    print(dist[n - 1][m - 1])
    return


bfs()
