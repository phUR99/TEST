import sys
from heapq import heapify, heappush, heappop

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input().strip())

heap = list(map(int, sys.stdin.readlines()))
heapify(heap)

ret = 0
while len(heap) > 1:
    a = heappop(heap)
    b = heappop(heap)
    ret += a + b
    heappush(heap, a + b)

print(ret)
