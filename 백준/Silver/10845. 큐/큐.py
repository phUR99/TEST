import sys
from collections import deque

dq = deque()
n = int(sys.stdin.readline().strip())
while n:
    n -= 1
    query = list(sys.stdin.readline().strip().split())
    if query[0] == "push":
        val = int(query[1])
        dq.append(val)
    elif query[0] == "front":
        if not dq:
            print(-1)
        else:
            print(dq[0])
    elif query[0] == "back":
        if not dq:
            print(-1)
        else:
            print(dq[-1])
    elif query[0] == "size":
        print(len(dq))
    elif query[0] == "pop":
        if not dq:
            print(-1)
        else:
            print(dq.popleft())
    else:
        print(int(len(dq) == 0))