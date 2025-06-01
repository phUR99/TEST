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


def solve(start):

    stack = [(start, False)]
    while stack:
        here, done = stack.pop()
        if done:
            l = 1
            for nxt in adj[here]:
                if heights[nxt] > heights[here]:
                    l = max(l, 1 + cache[nxt])
            cache[here] = l
        else:
            if cache[here] != -1:
                continue
            stack.append((here, True))
            for nxt in adj[here]:
                if heights[nxt] > heights[here] and cache[nxt] == -1:
                    stack.append((nxt, False))


for i in range(1, n + 1):
    if cache[i] == -1:
        solve(i)
    print(f"{cache[i]}\n")
