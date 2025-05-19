import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n, l = map(int, input().strip().split())

arr = list(map(int, input().strip().split()))
dq = deque()

for i in range(n):
    if dq and dq[0] < i - l + 1:
        dq.popleft()
    while dq and arr[dq[-1]] > arr[i]:
        dq.pop()
    dq.append(i)
    print(arr[dq[0]], end=" ")
