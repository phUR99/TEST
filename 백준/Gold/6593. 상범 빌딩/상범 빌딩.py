import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

while 1:
    l, r, c = map(int, input().strip().split())
    if not l and not r and not c:
        break

    def solve():
        board = [
            [line for _ in range(r + 1) for line in [input().strip()] if line != ""]
            for _ in range(l)
        ]
        dist = [[[-1 for _ in range(c)] for _ in range(r)] for _ in range(l)]
        dx = [-1, 1, 0, 0, 0, 0]
        dy = [0, 0, -1, 1, 0, 0]
        dz = [0, 0, 0, 0, -1, 1]

        def oob(x, y, z):
            return x < 0 or x >= l or y < 0 or y >= r or z < 0 or z >= c

        def find(s):
            for i in range(l):
                for j in range(r):
                    for k in range(c):
                        if board[i][j][k] == s:
                            return (i, j, k)

        q = deque()
        sx, sy, sz = find("S")
        q.append((sx, sy, sz))
        dist[sx][sy][sz] = 0
        while q:
            hx, hy, hz = q.popleft()
            for dir in range(6):
                nx = hx + dx[dir]
                ny = hy + dy[dir]
                nz = hz + dz[dir]
                if oob(nx, ny, nz):
                    continue
                if board[nx][ny][nz] == "#" or dist[nx][ny][nz] != -1:
                    continue
                dist[nx][ny][nz] = dist[hx][hy][hz] + 1
                q.append((nx, ny, nz))
        ex, ey, ez = find("E")
        if dist[ex][ey][ez] == -1:
            print("Trapped!")
        else:
            print(f"Escaped in {dist[ex][ey][ez]} minute(s).")

    solve()
