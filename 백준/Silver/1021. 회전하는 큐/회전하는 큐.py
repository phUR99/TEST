import sys
from collections import deque

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

n, m = map(int, input().strip().split())
arr = list(map(int, input().strip().split()))

dq = deque([i + 1 for i in range(n)])
ret = 0
for a in arr:
    l, r = (0, 0)
    mod = len(dq)
    while dq[r % mod] != a:
        r += 1
    while dq[(-l + mod % mod)] != a:
        l += 1
    dir = min(l, r)
    if l > r:
        dq.rotate(l)
    else:
        dq.rotate(-r)
    dq.popleft()
    ret += dir

print(ret)
