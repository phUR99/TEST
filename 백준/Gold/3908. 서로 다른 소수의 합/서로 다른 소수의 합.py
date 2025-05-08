import sys


t = int(sys.stdin.readline().strip())


prime = [1 for _ in range(1120 + 1)]
prime[0] = prime[1] = 0
for i in range(1120 + 1):
    if prime[i]:
        for j in range(i * i, 1120 + 1, i):
            prime[j] = 0
p = []
for i in range(len(prime)):
    if prime[i]:
        p.append(i)


def solve():
    n, k = map(int, sys.stdin.readline().strip().split())
    cache = [[0 for _ in range(k + 1)] for _ in range(n + 1)]
    """
    @cache
    def caching(idx, weight, remain):
        if idx == len(p):
            return int(remain == 0 and weight == 0)
        ret = caching(idx + 1, weight, remain)
        if weight - p[idx] >= 0 and remain:
            ret += caching(idx + 1, weight - p[idx], remain - 1)
        return ret
    """
    cache[0][0] = 1
    for pp in p:
        for i in range(n, pp - 1, -1):
            for j in range(1, k + 1):
                cache[i][j] += cache[i - pp][j - 1]
    print(cache[n][k])


for _ in range(t):
    solve()
