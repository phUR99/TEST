import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

m, n = map(int, input().strip().split())


arr = [[0 for _ in range(m)] for _ in range(m)]
tmp = [1 for _ in range(2 * m - 1)]

for _ in range(n):
    z, o, t = map(int, input().strip().split())
    cur = [0] * z + [1] * o + [2] * t
    for i in range(2 * m - 1):
        tmp[i] += cur[i]

for i in range(m):
    arr[m - 1 - i][0] += tmp[i]
for i in range(m, 2 * m - 1):
    arr[0][i + 1 - m] += tmp[i]

for i in range(1, m):
    for j in range(1, m):
        arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j], arr[i][j - 1])


for i in range(m):
    print(*arr[i])
