import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline


n = int(input().strip())
dq = deque([(i + 1, r) for i, r in enumerate(list(map(int, input().strip().split())))])
while 1:
    idx, dir = dq.popleft()
    print(idx, end=" ")
    if not dq:
        break

    if dir > 0:
        dq.rotate(-(dir - 1))
    else:
        dq.rotate(-dir)
