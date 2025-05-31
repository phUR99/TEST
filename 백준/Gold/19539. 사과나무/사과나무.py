import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input().strip())

heap = list(map(int, input().strip().split()))
if sum(heap) % 3:
    print("NO")
    exit(0)

cnt = 0
day = sum(heap) // 3
for i in range(n):
    cnt += heap[i] // 2

if cnt >= day:
    print("YES")
else:
    print("NO")
