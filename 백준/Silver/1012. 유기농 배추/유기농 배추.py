import sys
import copy
from collections import deque
t = int(sys.stdin.readline().strip())


def solve():
    m, n, k = map(int, sys.stdin.readline().strip().split())
    board = [[0 for _ in range(n)] for _ in range(m)]
    visited = copy.deepcopy(board)
    for _ in range(k):
        x, y = map(int, sys.stdin.readline().strip().split())
        board[x][y] = 1
    ret = 0
    def bfs(i, j):
        q = deque()
        q.append((i, j))
        visited[i][j] = 1
        def oob(x, y):
            return x < 0 or x >= m or y <0 or y >= n
        dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        while q:
            here = q.popleft()
            for dx, dy in dir:
                nx = dx + here[0]
                ny = dy + here[1]
                if oob(nx, ny):
                    continue
                if visited[nx][ny] or not board[nx][ny]:
                    continue
                visited[nx][ny] = 1
                q.append((nx, ny))
            
    for i in range(m):
        for j in range(n):
            if visited[i][j] or not board[i][j]:
                continue
            bfs(i, j)
            ret += 1 
            
    print(ret)
    return


while t:
    t -= 1
    solve()