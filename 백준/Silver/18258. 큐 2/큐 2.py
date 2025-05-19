import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
q = deque()

n = int(input().strip())

for _ in range(n):
    cur = list(input().strip().split())
    if cur[0] == "push":
        q.append(cur[1])
    elif cur[0] == "front":
        print(q[0] if q else -1)
    elif cur[0] == "back":
        print(q[-1] if q else -1)
    elif cur[0] == "pop":
        print(q.popleft() if q else -1)
    elif cur[0] == "empty":
        print(0 if q else 1)
    elif cur[0] == "size":
        print(len(q))
