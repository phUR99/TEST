import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
s = []

for _ in range(n):
    cur = list(map(int, input().strip().split()))
    if cur[0] == 1:
        s.append(cur[1])
    elif cur[0] == 2:
        if not s:
            print(-1)
        else:
            now = s.pop()
            print(now)
    elif cur[0] == 3:
        print(len(s))
    elif cur[0] == 4:
        print(1 if not s else 0)
    else:
        if not s:
            print(-1)
        else:
            print(s[-1])
