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
        print(s.pop() if s else -1)
    elif cur[0] == 3:
        print(len(s))
    elif cur[0] == 4:
        print(0 if s else 1)
    else:
        print(s[-1] if s else -1)
