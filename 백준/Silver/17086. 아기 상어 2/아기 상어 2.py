import sys
from collections import deque
n, m = map(int, sys.stdin.readline().strip().split())
board = []

for i in range(n):
    #list 변환
    row = list(map(int, sys.stdin.readline().strip().split()))
    board.append(row)
    
def bfs():
    dx = [-1, 1, 0, 0, 1, 1, -1, -1]
    dy = [0, 0, -1, 1, 1, -1, -1, 1]
    dist = [[-1 for _ in range(m)] for _ in range(n)]
    
    q = deque()
    
    for i in range(n):
        for j in range(m):
            if board[i][j]:
                q.append((i, j))
                dist[i][j] = 0
    
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
    return dist
    

ret = bfs()
print(max(map(max, ret)))
