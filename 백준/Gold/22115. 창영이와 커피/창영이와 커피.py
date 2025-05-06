import sys

n, k = map(int, sys.stdin.readline().strip().split())

arr = list(map(int, sys.stdin.readline().strip().split()))
if sum(arr) < k:
    print(-1)
    exit(0)

cache = [int(1e9) for _ in range(100000 + 1)]
cache[0] = 0
for i in range(n):
    for j in range(k + 1, arr[i] - 1, -1):
        cache[j] = min(cache[j], cache[j - arr[i]] + 1)

print(-1 if cache[k] == int(1e9) else cache[k])
