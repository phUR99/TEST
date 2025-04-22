import sys
n, k = map(int, sys.stdin.readline().strip().split())

arr = [i + 1 for i in range(n)]
idx = 0
ret = []
while arr:
    idx = (idx + k - 1) % len(arr)
    ret.append(arr.pop(idx))
res = "<" + ", ".join(map(str, ret)) + ">"
print(res)
