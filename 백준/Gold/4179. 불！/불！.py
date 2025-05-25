import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

r, c = map(int, input().strip().split())

board = [input().strip() for _ in range(r)]

dist_fire = [[-1 for _ in range(c)] for _ in range(r)]
dist_jihun = [[-1 for _ in range(c)] for _ in range(r)]


q = deque()


def find_pos(s):
    ret = []
    for i in range(r):
        for j in range(c):
            if board[i][j] == s:
                ret.append((i, j))
    return ret


def oob(x, y):
    return x < 0 or x >= r or y < 0 or y >= c


arr = find_pos("F")

q.extend(arr)
for a in arr:
    x, y = a
    dist_fire[x][y] = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
while q:
    hx, hy = q.popleft()
    for dir in range(4):
        nx = dx[dir] + hx
        ny = dy[dir] + hy
        if oob(nx, ny):
            continue
        if dist_fire[nx][ny] != -1 or board[nx][ny] == "#":
            continue
        dist_fire[nx][ny] = dist_fire[hx][hy] + 1
        q.append((nx, ny))

arr = find_pos("J")
q.extend(arr)
for a in arr:
    x, y = a
    dist_jihun[x][y] = 0

while q:
    hx, hy = q.popleft()
    for dir in range(4):
        nx = dx[dir] + hx
        ny = dy[dir] + hy
        if oob(nx, ny):
            print(dist_jihun[hx][hy] + 1)
            exit(0)
        if dist_jihun[nx][ny] != -1 or board[nx][ny] == "#":
            continue
        if dist_fire[nx][ny] != -1 and dist_jihun[hx][hy] + 1 >= dist_fire[nx][ny]:
            continue
        dist_jihun[nx][ny] = dist_jihun[hx][hy] + 1
        q.append((nx, ny))

print("IMPOSSIBLE")
