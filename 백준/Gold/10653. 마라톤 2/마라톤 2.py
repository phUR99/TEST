import sys

n, k = map(int, sys.stdin.readline().strip().split())

arr = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]

cache = [[987654321 for _ in range(k + 1)] for _ in range(n)]


def dist(i, j):
    return abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1])


cache[0][0] = 0
for i in range(1, n):
    for j in range(0, k + 1):
        for l in range(1, i + 1):
            if l - 1 > j:
                break
            cache[i][j] = min(cache[i][j], cache[i - l][j - l + 1] + dist(i, i - l))

print(min(cache[n - 1]))
