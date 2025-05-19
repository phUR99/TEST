import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n = int(input().strip())
arr = [int(input().strip()) for _ in range(n)]
s = []
ret = 0
for a in arr:
    cnt = 1
    while s and s[-1][0] <= a:
        ret += s[-1][1]
        if a == s[-1][0]:
            cnt += s[-1][1]
        s.pop()
    if s:
        ret += 1
    s.append((a, cnt))
print(ret)
