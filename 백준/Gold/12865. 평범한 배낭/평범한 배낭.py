import sys

n, k = map(int, sys.stdin.readline().strip().split())
cache = [0 for _ in range(k + 1)]

for _ in range(n):
    w, v = map(int, sys.stdin.readline().strip().split())
    for i in range(k, w - 1, -1):
        cache[i] = max(cache[i], cache[i - w] + v)

print(cache[k])
