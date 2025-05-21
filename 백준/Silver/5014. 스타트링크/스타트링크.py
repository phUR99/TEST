import sys
from collections import deque

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

f, s, g, u, d = map(int, input().strip().split())


dist = [-1 for _ in range(1000000 + 5)]


def bfs():
    q = deque()
    q.append(s)
    dist[s] = 0

    while q:
        here = q.popleft()

        for dir in (u, -d):
            there = here + dir
            if there < 1 or there > f:
                continue
            if dist[there] != -1:
                continue
            dist[there] = dist[here] + 1
            q.append(there)


bfs()
if dist[g] == -1:
    print("use the stairs")
else:
    print(dist[g])
