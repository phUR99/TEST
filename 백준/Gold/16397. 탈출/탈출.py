import sys
from collections import deque

n, t, g = map(int, sys.stdin.readline().strip().split())
q = deque()
dist = [-1 for _ in range(100000)]

dist[n] = 0
q.append(n)

while q:
    here = q.popleft()

    there = here + 1
    if there < 100000 and dist[there] == -1:
        dist[there] = dist[here] + 1
        q.append(there)
    there = here * 2
    if there < 100000:
        digit = 1
        while there >= digit * 10:
            digit *= 10
        there = max(0, there - digit)
        if dist[there] == -1:
            dist[there] = dist[here] + 1
            q.append(there)

if dist[g] != -1 and dist[g] <= t:
    print(dist[g])
else:
    print("ANG")
