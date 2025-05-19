import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n = int(input().strip())

arr = [int(input().strip()) for _ in range(n)]
s = []
ret = 0
for a in arr:
    while s and s[-1] <= a:
        s.pop()
    ret += len(s)
    s.append(a)
print(ret)
