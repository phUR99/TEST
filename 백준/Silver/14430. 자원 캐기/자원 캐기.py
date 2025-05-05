import sys
from functools import cache

n, m = map(int, sys.stdin.readline().strip().split())

arr = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]

@cache
def solve(x, y):
    if x == n -1 and y == m - 1:
        return arr[x][y]

    ret = 0
    if x < n - 1:
        ret = max(ret, arr[x][y] + solve(x + 1, y))
    if y < m - 1:
        ret = max(ret, arr[x][y] + solve(x, y + 1))
    return ret    
    
print(solve(0, 0))    
    