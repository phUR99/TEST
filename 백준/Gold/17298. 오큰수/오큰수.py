import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input().strip())

arr = list(map(int, input().strip().split()))
ret = [-1] * n
s = []
for i in range(n):
    while s and arr[s[-1]] < arr[i]:
        ret[s.pop()] = arr[i]
    s.append(i)
print(*ret, sep=" ")
