import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
t = int(input().strip())
dx = [1, 2, 2, 1, -1, -2, -2, -1]
dy = [-2, -1, 1, 2, 2, 1, -1, -2]


ret = []

for _ in range(t):

    def bfs():
        l = int(input().strip())
        hx, hy = map(int, input().strip().split())
        gx, gy = map(int, input().strip().split())
        dist = [[-1 for _ in range(l)] for _ in range(l)]
        q = deque()
        q.append((hx, hy))
        dist[hx][hy] = 0

        while q:
            x, y = q.popleft()
            for dir in range(len(dx)):
                nx = x + dx[dir]
                ny = y + dy[dir]
                if nx < 0 or nx >= l or ny < 0 or ny >= l:
                    continue
                if dist[nx][ny] != -1:
                    continue
                dist[nx][ny] = dist[x][y] + 1
                if (nx, ny) == (gx, gy):
                    return dist[gx][gy]
                q.append((nx, ny))
        return dist[gx][gy]

    ret.append(bfs())

print(*ret, sep="\n")
