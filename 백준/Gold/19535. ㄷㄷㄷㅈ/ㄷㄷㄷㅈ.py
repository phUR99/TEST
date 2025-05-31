import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline


n = int(input().strip())
adj = [[] for _ in range(n + 1)]
indegree = [0 for _ in range(n + 1)]

for _ in range(n - 1):
    u, v = map(int, input().strip().split())
    adj[u].append(v)
    adj[v].append(u)
    indegree[u] += 1
    indegree[v] += 1

ret = 0


def solve(here, parent, cnt):
    if cnt == 3:
        return 1
    ret = 0
    for nxt in adj[here]:
        if nxt == parent:
            continue
        ret += solve(nxt, here, cnt + 1)
    return ret


for i in range(1, n + 1):
    for there in adj[i]:
        if i < there:
            ret += (indegree[i] - 1) * (indegree[there] - 1)
    ret -= 3 * max(0, indegree[i] * (indegree[i] - 1) * (indegree[i] - 2) // 6)

if ret == 0:
    print("DUDUDUNGA")
elif ret > 0:
    print("D")
else:
    print("G")
