import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

s = []
k = int(input().strip())
for _ in range(k):
    cur = int(input().strip())
    s.append(cur) if cur else s.pop()
print(sum(s))
