import sys
from functools import cache

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

while 1:
    m, n = map(int, input().strip().split())
    if not m and not n:
        break
    board = [list(map(int, input().strip().split())) for _ in range(m)]
    cache = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        cache[i][0] = board[i][0]
        if n >= 2:
            cache[i][1] = max(board[i][0], board[i][1])

        for j in range(2, n):
            cache[i][j] = max(cache[i][j - 2] + board[i][j], cache[i][j - 1])
    arr = [cache[i][n - 1] for i in range(m)]

    cache = [0 for _ in range(m)]
    # print(arr)
    cache[0] = arr[0]
    if m >= 2:
        cache[1] = max(arr[0], arr[1])

    for i in range(2, m):
        cache[i] = max(cache[i - 2] + arr[i], cache[i - 1])
    print(cache[m - 1])
