import sys

n, m = map(int, sys.stdin.readline().strip().split())
arr = [0] + list(int(sys.stdin.readline().strip()) for _ in range(n))

cache = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, m + 1):
        cache[i][j] = cache[i - 1][j - 1] + arr[i]
    for j in range(1, m + 1):
        if i - j < 0:
            break
        cache[i][0] = max(cache[i][0], cache[i - j][j], cache[i - j][0])
print(cache[n][0])
