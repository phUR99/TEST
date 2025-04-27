import sys


n, m, k = map(int, sys.stdin.readline().strip().split())
arr = []
for _ in range(n):
    x, y = map(int, sys.stdin.readline().strip().split())
    arr.append([x, y])
cache = [[[-1 for _ in range(k+1)] for _ in range(m+1)] for _ in range(n)]

def solve(idx: int, remain_cheese: int, remain_potato: int):
    if idx == n:
        return 0
    if cache[idx][remain_cheese][remain_potato] != -1:
        return cache[idx][remain_cheese][remain_potato]
    
    ret = solve(idx + 1, remain_cheese, remain_potato)
    nxt_cheese = remain_cheese - arr[idx][0]
    nxt_potato = remain_potato - arr[idx][1]
    if remain_cheese - arr[idx][0] >= 0 and remain_potato - arr[idx][1] >= 0:
        ret = max(ret, 1 + solve(idx+1, nxt_cheese, nxt_potato))
    cache[idx][remain_cheese][remain_potato] = ret
    return ret

ret = solve(0, m, k)
print(ret)