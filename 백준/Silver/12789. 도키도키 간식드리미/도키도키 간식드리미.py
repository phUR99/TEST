import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n = int(input().strip())
arr = list(map(int, input().strip().split()))

order = 1
s = []
for a in arr:
    if a == order:
        order += 1
    else:
        while s and order == s[-1]:
            s.pop()
            order += 1
        if a == order:
            order += 1
            continue
        if not s or s[-1] > a:
            s.append(a)
        else:
            print("Sad")
            exit(0)


print("Nice")
