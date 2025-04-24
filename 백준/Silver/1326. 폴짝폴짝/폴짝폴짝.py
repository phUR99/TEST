import sys
from collections import deque
n = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().strip().split()))
s, e = map(int, sys.stdin.readline().strip().split())
s -= 1
e -= 1


def bfs():
    dist = [-1 for _ in range(n)]
    dist[s] = 0
    q = deque()
    q.append(s)
    
    while q:
        here = q.popleft()
        mul = arr[here]
        for there in range(here, -1, -mul):
            if dist[there] != -1:
                continue
            dist[there] = dist[here] + 1
            q.append(there)
        for there in range(here, n, +mul):
            if dist[there] != -1:
                continue
            dist[there] = dist[here] + 1
            q.append(there)
            
    return dist[e]

print(bfs())
