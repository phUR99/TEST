import math
n = int(input())
arr = [*map(int, input().split())]

def solve(x):    
    ret = 0
    for i in range(n):
        ret += abs(arr[i] - i * x)
    return ret

l ,r = 1, int(1e9)
while r - l >= 3:
    ml = int((l*2+r)/3)
    mr = int((l+2*r)/3)
    if(solve(ml) > solve(mr)):
        l = ml
    else:
        r = mr
ret = float('inf')
for i in range(l, r+1):
    ret = min(ret, solve(i))
print(ret)


        