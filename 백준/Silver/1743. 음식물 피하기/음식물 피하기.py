import sys
from collections import deque
n, m, k = map(int, sys.stdin.readline().strip().split())
board = [[0 for _ in range(m)] for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]

for _ in range(k):
    x, y = map(int, sys.stdin.readline().strip().split())
    x -= 1
    y -= 1
    board[x][y] = 1
    
def solve():
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    def oob(x: int, y: int):
        return x < 0 or x >= n or y < 0 or y >= m
    
    def bfs(x: int, y: int):
        q = deque()
        q.append((x, y))
        visited[x][y] = 1
        cnt = 0
        while q:
            here = q.popleft()
            cnt += 1
            #print(here)
            for ddx, ddy in zip(dx, dy):
                nx = ddx + here[0]
                ny = ddy + here[1]
                if oob(nx, ny):
                    continue
                if not board[nx][ny] or visited[nx][ny]:
                    continue
                visited[nx][ny] = True
                q.append((nx, ny))
        return cnt
    
    ret = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] and not visited[i][j]:
                ret = max(ret, bfs(i, j))
    print(ret)
    
solve()
            
            
        
            
    
        