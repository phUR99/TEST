from functools import cache
import sys
sys.setrecursionlimit(10**6)

def solve():
    n, u, d = map(float, sys.stdin.readline().strip().split())
    n = int(n)
    s = 1.0 - u - d
    
    @cache
    def caching(idx: int, right: int) -> float:
        if idx == 0: 
            return right
        ret = 0
        if u:
            ret += u * caching(idx-1, right+1) - u
        if d:
            ret += d * caching(idx-1, max(right-1, 0)) + d 
        if s:
            ret += s * caching(idx-1, right)    
        return ret
    
    ret = caching(n, 0)
    print(f"{ret:.4f}")

t = int(sys.stdin.readline().strip())
while t:
    t -= 1
    solve()