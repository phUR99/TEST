import sys

n, m = map(int, sys.stdin.readline().strip().split())
board = [sys.stdin.readline().strip() for _ in range(n)]


full_bit = (1<<20)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

    
def oob(x, y):
    return x < 0 or x >= n or y < 0 or y >= m

def find():
    ret = []
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'o':
                ret.append((i, j))
    return ret

arr = find()

def solve(state):
    cnt = 0

    x1, y1 = arr[0]
    x2, y2 = arr[1]
    while cnt < 10:
        cnt += 1 
        dir = state & 3
        state >>= 2
        nx1, ny1 = x1 + dx[dir], y1 + dy[dir]
        nx2, ny2 = x2 + dx[dir], y2 + dy[dir]
        if oob(nx1, ny1) and oob(nx2, ny2):
            return 987654321
        if oob(nx1, ny1) or oob(nx2, ny2):
            return cnt
        if board[nx1][ny1] != '#':
            x1, y1 = nx1, ny1
        if board[nx2][ny2] != '#':
            x2, y2 = nx2, ny2
        if x1 == x2 and y1 == y2:
            return 987654321      
    return 987654321

ret = 987654321
for state in range(full_bit):
    ret = min(ret, solve(state))
if ret == 987654321:
    ret = -1
print(ret)