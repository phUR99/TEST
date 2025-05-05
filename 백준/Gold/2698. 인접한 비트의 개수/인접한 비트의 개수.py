import sys
from functools import cache
def main():
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        solve()
        
        
def solve():
    n, k = map(int, sys.stdin.readline().strip().split())
    
    @cache
    def caching(idx, cur, prev):
        if idx == n:
            return cur == k
        
        ret = caching(idx+1, cur + prev * 0, 0) + caching(idx+1, cur + prev * 1, 1)
        return ret
    print(caching(0, 0, 0))        

main()