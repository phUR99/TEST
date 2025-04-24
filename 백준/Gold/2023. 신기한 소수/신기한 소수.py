import sys

def solve():
    n:int = int(1e5)
    N:int = int(sys.stdin.readline().strip())
    
    def define():
    
        ret = [True for _ in range(n+1)]
        ret[0] = ret[1] = False
        
        for i in range(n + 1):
            if not ret[i]:
                continue
            for j in range(i * i, n + 1, i):
                ret[j] = False
        '''
        for i, state in enumerate(ret):
            print(i, state)
        '''
        res = []
        for i, state in enumerate(ret):
            if state:
                res.append(i)
                
        return res
    
    arr = define()
    ret = []

    def prime(cur: int) -> bool:
        for i in arr:
            if i == cur:
                continue
            if cur % i == 0 or cur == 0 or cur == 1:
                return False
        return True
        
    
    def recursion(idx: int, now: int):
        if idx == N:
            ret.append(now)
            return
        
        if idx == 0:
            start = 1
        else:    
            start = 0
            
        for i in range(start, 10):
            nxt = now * 10 + i
            if prime(nxt):
                recursion(idx+1, nxt)
    recursion(0, 0)
    sorted(ret)
    print(*ret, sep='\n')
    
solve()