import sys
sys.setrecursionlimit(10000000)



def tiling(n):
    if n <= 1 : return 1

    if cache[n] != -1 : return cache[n]

    cache[n] = (tiling(n-1) + tiling(n-2)) %10007
    return cache[n]

n = int(input())
cache = [-1 for i in range(n+1)]



print(tiling(n))