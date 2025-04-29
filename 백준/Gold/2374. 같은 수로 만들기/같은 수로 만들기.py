import sys
from collections import deque

n = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readlines()))
sorted_arr = sorted(set(arr))

s = deque()

ret = 0

for i in range(1, len(sorted_arr)):
    cnt = 0
    for j in range(len(arr)):
        if arr[j] != sorted_arr[i-1]:
            continue
        if not s or s[-1] + 1 != j:
            cnt += 1    
        s.append(j)
    ret += cnt * (sorted_arr[i] - sorted_arr[i-1])
    while s:
        idx = s.pop()
        arr[idx] = sorted_arr[i]
        
print(ret)