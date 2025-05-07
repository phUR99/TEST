import sys

arr = sys.stdin.readlines()
arr = [list(map(int, a.strip().split())) for a in arr]
cache = [[[0 for _ in range(16)] for _ in range(16)] for _ in range(len(arr))]
cache[0][1][0] = arr[0][0]
cache[0][0][1] = arr[0][1]

for i in range(1, len(arr)):
    for j in range(16):
        for k in range(16):
            cache[i][j][k] = cache[i - 1][j][k]
            if j > 0:
                cache[i][j][k] = max(cache[i][j][k], cache[i - 1][j - 1][k] + arr[i][0])
            if k > 0:
                cache[i][j][k] = max(cache[i][j][k], cache[i - 1][j][k - 1] + arr[i][1])


print(cache[len(arr) - 1][15][15])
