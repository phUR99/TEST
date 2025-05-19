import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input().strip())
start = 1
ret = []
arr = [int(input().strip()) for _ in range(n)]
s = []
for a in arr:
    while start <= a:
        ret.append("+")
        s.append(start)
        start += 1
    if s[-1] == a:
        s.pop()
        ret.append("-")
    else:
        print("NO")
        exit(0)
print(*ret, sep="\n")
