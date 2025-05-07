import sys

n = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().strip().split()))
arr = [-1 if a == 2 else 1 for a in arr]
cache = [[0, 0] for _ in range(n)]
cache[0][1] = arr[0]
for i in range(1, n):
    cache[i][0] = max(cache[i - 1][0], cache[i - 1][1])
    cache[i][1] = max(0, cache[i - 1][1]) + arr[i]

ret = max(cache[n - 1][0], cache[n - 1][1])
cache = [[0, 0] for _ in range(n)]
cache[0][1] = arr[0]
for i in range(1, n):
    cache[i][0] = min(cache[i - 1][0], cache[i - 1][1])
    cache[i][1] = min(0, cache[i - 1][1]) + arr[i]
ret = max(ret, max(abs(cache[n - 1][1]), abs(cache[n - 1][0])))
print(ret)
