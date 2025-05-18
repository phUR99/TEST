import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n = int(input().strip())
arr = list(map(int, input().strip().split()))

order = 1
s = []
for a in arr:
    s.append(a)
    while s and s[-1] == order:
        s.pop()
        order += 1

if not s:
    print("Nice")
else:
    print("Sad")
