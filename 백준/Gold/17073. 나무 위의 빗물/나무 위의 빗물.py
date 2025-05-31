import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, w = map(int, input().strip().split())

adj = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    u, v = map(int, input().strip().split())
    adj[u].append(v)
    adj[v].append(u)


def dfs(here, parent):

    ret = 0
    isLeaf = True
    for there in adj[here]:
        if there == parent:
            continue
        isLeaf = False
        ret += dfs(there, here)
    if isLeaf:
        return 1
    return ret


ret = w / dfs(1, -1)
print(f"{ret:3f}")
