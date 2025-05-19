import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

t = int(input().strip())
for _ in range(t):
    cmd = input().strip()
    n = int(input().strip())
    arr = input().strip()
    arr = arr[1:-1]

    if arr == "":
        arr = []
    else:
        arr = list(map(int, arr.strip().split(",")))
    dq = deque(arr)

    def solve():
        ret = []
        flip = False
        for c in cmd:
            if c == "R":
                flip = not flip
            else:
                if not dq:
                    print("error")
                    return
                dq.pop() if flip else dq.popleft()

        while dq:
            ret.append(str(dq.pop() if flip else dq.popleft()))

        ans = "[" + ",".join(ret) + "]"
        print(ans)

    solve()
