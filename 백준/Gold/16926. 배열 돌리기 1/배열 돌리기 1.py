import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m, r = map(int, input().strip().split())

board = [list(map(int, input().strip().split())) for _ in range(n)]
tmp_board = [[0 for _ in range(m)] for _ in range(n)]


def recursion(u, d, l, r, repeat):
    if u >= d or l >= r:
        return
    num = (d - u - 1) + (r - l - 1)
    num *= 2
    now = repeat % num
    for _ in range(now):
        for i in range(u, d - 1):
            tmp_board[i + 1][l] = board[i][l]
        for i in range(l, r - 1):
            tmp_board[d - 1][i + 1] = board[d - 1][i]
        for i in range(d - 1, u, -1):
            tmp_board[i - 1][r - 1] = board[i][r - 1]
        for i in range(r - 1, l, -1):
            tmp_board[u][i - 1] = board[u][i]
        for i in range(l, r):
            board[u][i] = tmp_board[u][i]
            board[d - 1][i] = tmp_board[d - 1][i]
        for i in range(u, d):
            board[i][l] = tmp_board[i][l]
            board[i][r - 1] = tmp_board[i][r - 1]

    recursion(u + 1, d - 1, l + 1, r - 1, repeat)


recursion(0, n, 0, m, r)

for b in board:
    print(*b)
