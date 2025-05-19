import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input().strip())
q = deque([i + 1 for i in range(n)])

while len(q) > 1:
    q.popleft()
    if len(q) <= 1:
        break
    q.append(q.popleft())

print(q[0])
