n = int(input())
arr = list(map(int, input().split()))
op = list(map(int, input().split()))
ops = [lambda x, y: x+y, lambda x,y : x-y, lambda x, y: x*y, lambda x, y : -(abs(x) // y) if x < 0  else x // y]
cnt = [0 for _ in range(4)]
import math
m = float("inf")
M = float("-inf")

def solve(idx, val):
    global op, cnt, m, M
    if(sum(op) == sum(cnt)):
        m = min(m, val)
        M = max(M, val)
        return    
    for i in range(4) :
        if cnt[i] < op[i]:
            cnt[i] += 1
            solve(idx+1, ops[i](val, arr[idx]))
            cnt[i] -= 1
        

solve(1, arr[0])        
print(M, m, sep='\n')
        
        
        
    