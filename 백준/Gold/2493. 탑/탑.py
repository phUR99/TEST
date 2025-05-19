import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n = int(input().strip())

arr = list(map(int, input().strip().split()))
arr = [987654321] + arr

s = [0]
ret = []
for i in range(1, n + 1):
    while arr[s[-1]] < arr[i]:
        s.pop()
    ret.append(s[-1])
    s.append(i)

print(*ret, sep=" ")
