import sys
from functools import cache
arr = sys.stdin.readline().strip()
n = len(arr)

@cache
def solve(idx):
    if idx == n:
        return 1
    ret = 0
    if int(arr[idx]) != 0:
        ret = solve(idx + 1)
    if int(arr[idx]) != 0 and idx < n - 1 and int(arr[idx : idx + 2]) <= 34:
        ret += solve(idx + 2)
    return ret

print(solve(0))