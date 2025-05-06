import sys
sys.setrecursionlimit(10**6)
from functools import cache

n = int(input())
MOD = int(1e9) + 7
@cache
def solve(idx, s1, s2):
    if idx == n:
        return not s1 and not s2
    ret = 0
    if s1 and s2:
        ret += solve(idx + 1, 0, 0)        
    if not s1 and s2:
        ret += solve(idx + 1, 1, 0)
        ret += solve(idx + 1, 0, 0)
    if s1 and not s2:
        ret += solve(idx + 1, 0, 1)
        ret += solve(idx + 1, 0, 0)
    if not s1 and not s2:
        ret += solve(idx + 1, 0, 0) * 2
        ret += solve(idx + 1, 1, 1)
        ret += solve(idx + 1, 0, 1)
        ret += solve(idx + 1, 1, 0)
    ret %= MOD
    return ret 

cache = [[[0 for _ in range(2)] for _ in range(2)] for _ in range(n+1)]
cache[0][0][0] = 1
for i in range(1, n+1):
    cache[i][0][0] = (cache[i-1][0][0] * 2 + cache[i-1][1][1] + cache[i-1][0][1] + cache[i-1][1][0]) % MOD
    cache[i][1][0] = (cache[i-1][0][1] + cache[i-1][0][0]) % MOD
    cache[i][0][1] = (cache[i-1][1][0] + cache[i-1][0][0]) % MOD
    cache[i][1][1] = (cache[i-1][0][0]) % MOD
print(cache[n][0][0] % MOD)
            
