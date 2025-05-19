import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n, k = map(int, input().strip().split())

q = deque([str(i + 1) for i in range(n)])

ret = []
while q:
    for _ in range(k - 1):
        q.append(q.popleft())
    ret.append(q.popleft())


ans = "<" + ", ".join(ret) + ">"
print(ans)
