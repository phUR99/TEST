import sys

n = int(sys.stdin.readline().strip())
s = set(list(map(int, sys.stdin.readline().strip().split())))
m = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().strip().split()))
arr = [1 if a in s else 0 for a in arr]
print(*arr)
