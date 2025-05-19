import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

while 1:
    line = list(map(int, input().strip().split()))
    n = line[0]
    if n == 0:
        break
    arr = line[1:] + [-1]
    s = []
    ret = 0
    for i in range(n + 1):
        start = i
        while s and s[-1][1] >= arr[i]:
            start, height = s.pop()
            ret = max(ret, (i - start) * height)
        s.append([start, arr[i]])
    print(ret)
