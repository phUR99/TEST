import sys
n = str(sys.stdin.readline().strip())
arr = [0 for _ in range(10)]
for i in n:
    arr[ord(i) - ord('0')] += 1 

M = 0
for i, val in enumerate(arr):
    if i == 6 or i == 9:
        continue
    M = max(M, arr[i])
M = max(M, (arr[6] + arr[9] + 1) // 2)
print(M)