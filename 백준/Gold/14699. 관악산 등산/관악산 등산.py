import sys


sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().split())
heights = [0]
heights.extend(list(map(int, input().split())))
adj = [set() for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].add(v)
    adj[v].add(u)

cache = [-1 for _ in range(n + 1)]


def solve(here):
    if cache[here] != -1:
        return cache[here]
    ret = 1
    for there in adj[here]:
        if heights[there] > heights[here]:
            ret = max(ret, solve(there) + 1)
    cache[here] = ret
    return ret


for i in range(1, n + 1):
    print(f"{solve(i)}\n")
