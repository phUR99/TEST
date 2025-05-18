import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n = int(input().strip())

isStack = list(map(int, input().strip().split()))

qs = list(map(int, input().strip().split()))
qs = [r for i, r in enumerate(qs) if not isStack[i]]
qs.reverse()
m = int(input().strip())
arr = list(map(int, input().strip().split()))
qs.extend(arr)
print(*qs[:m])
