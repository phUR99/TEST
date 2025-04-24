import sys
from collections import deque
n, m = map(int, sys.stdin.readline().strip().split())
board = []

for i in range(n):
    #list 변환
    row = list(map(int, sys.stdin.readline().strip().split()))
    board.append(row)
    
def bfs(x, y):
    dx = [-1, 1, 0, 0, 1, 1, -1, -1]
    dy = [0, 0, -1, 1, 1, -1, -1, 1]
    dist = [[-1 for _ in range(m)] for _ in range(n)]
    dist[x][y] = 0
    q = deque()
    q.append((x, y))
    
    def oob(x, y):
        return x < 0 or x >= n or y < 0 or y >= m
     
    while q:
        r, c = q.popleft()
        for i in range(8):
            nx = r + dx[i]
            ny = c + dy[i]
            if oob(nx, ny): continue
            if dist[nx][ny] != -1: continue
            dist[nx][ny] = dist[r][c] + 1
            q.append((nx, ny))
    ret = 987654321
    for i in range(n):
        for j in range(m):
            if board[i][j] == 1:
                if (x, y) == (i, j):
                    continue
                ret = min(ret, dist[i][j])
    return ret
    

ret = 0
for i in range(n):
    for j in range(m):
        if not board[i][j]:
            ret = max(ret, bfs(i, j))
print(ret)
