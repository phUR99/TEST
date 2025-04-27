
from collections import deque
import sys
dist = dict()

q = deque()

n, k = map(int, sys.stdin.readline().strip().split())

arr = list(map(int, sys.stdin.readline().strip().split()))

for element in arr:
    dist[element] = 0
    q.append(element)

ret: int = 0
while q:
    here = q.popleft()
    
    there = here - 1;
    if there not in dist:
        dist[there] = dist[here] + 1
        k -= 1
        ret += dist[there]
        if not k:
            break
        q.append(there)
    there = here + 1
    if there not in dist:
        dist[there] = dist[here] + 1
        k -= 1
        ret += dist[there]
        if not k:
            break
        q.append(there)
sys.stdout.write(f"{ret}")