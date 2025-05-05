import sys
n = int(sys.stdin.readline().strip())
MAX = 250 * 250
cache = [0 for _ in range(MAX + 1)]
sum = 0
for _ in range(n):
    a, b = map(int, sys.stdin.readline().strip().split())
    for i in range(MAX, -1, -1):
        cache[i] += b
        if i >= a:
            cache[i] = min(cache[i], cache[i-a])
            
ret = int(1e9)
for i in range(MAX + 1):
    ret = min(ret, max(i, cache[i]))
print(ret)

        
