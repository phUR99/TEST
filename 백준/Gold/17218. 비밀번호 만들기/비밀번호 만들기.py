import sys

a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()
n = len(a)
m = len(b)

cache = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

for i in range(0, n):
    for j in range(0, m):
        if a[i] == b[j]:
            cache[i + 1][j + 1] = max(cache[i + 1][j + 1], cache[i][j] + 1)
        else:
            cache[i + 1][j + 1] = max(cache[i][j + 1], cache[i + 1][j])

l = len(a)
r = len(b)
ret = ""
while l > 0 and r > 0:
    if cache[l][r] == cache[l - 1][r]:
        l -= 1
    elif cache[l][r] == cache[l][r - 1]:
        r -= 1
    else:
        ret = a[l - 1] + ret
        l -= 1
        r -= 1


print(ret)
