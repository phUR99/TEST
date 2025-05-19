import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n, k = map(int, input().strip().split())

dist = [-1 for _ in range(100000 + 1)]

q = deque()

q.append(n)
dist[n] = 0
while q:
    here = q.popleft()

    there = here + 1
    if there <= 100000 and dist[there] == -1:
        q.append(there)
        dist[there] = dist[here] + 1

    there = here - 1
    if there >= 0 and dist[there] == -1:
        q.append(there)
        dist[there] = dist[here] + 1

    there = here * 2
    if there <= 100000 and dist[there] == -1:
        q.append(there)
        dist[there] = dist[here] + 1

print(dist[k])
