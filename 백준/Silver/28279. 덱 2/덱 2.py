import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
dq = deque()
n = int(input().strip())

for _ in range(n):
    cur = list(map(int, input().strip().split()))
    if cur[0] == 1:
        dq.appendleft(cur[1])
    elif cur[0] == 2:
        dq.append(cur[1])
    elif cur[0] == 3:
        print(dq.popleft() if dq else -1)
    elif cur[0] == 4:
        print(dq.pop() if dq else -1)
    elif cur[0] == 5:
        print(len(dq))
    elif cur[0] == 6:
        print(0 if dq else 1)
    elif cur[0] == 7:
        print(dq[0] if dq else -1)
    elif cur[0] == 8:
        print(dq[-1] if dq else -1)
