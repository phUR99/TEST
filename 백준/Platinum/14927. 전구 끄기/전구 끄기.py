import sys
import copy

n = int(sys.stdin.readline().strip())

arr = [[0 for _ in range(n+2)]]  
for _ in range(n):
    row = list(map(int, sys.stdin.readline().strip().split()))
    arr.append([0] + row + [0])  
arr.append([0 for _ in range(n+2)])  

full_bit = (1 << n) - 1

    
def solve(state):
    ret = 0
    tmp = copy.deepcopy(arr)
    for i in range(n):
        if state & (1 << i):
            tmp[0][i+1] ^= 1
            tmp[1][i+1] ^= 1
            tmp[2][i+1] ^= 1
            tmp[1][i] ^= 1
            tmp[1][i+2] ^= 1
            ret += 1   
                  
    for i in range(2, n + 1):
        for j in range(1, n + 1):
            if tmp[i-1][j]:
                tmp[i-1][j] ^= 1
                tmp[i][j] ^= 1
                tmp[i+1][j] ^= 1
                tmp[i][j-1] ^= 1
                tmp[i][j+1] ^= 1
                ret += 1
                
    for i in range(1, n+1):
        for j in range(1, n+1):
            if tmp[i][j]:
                return 987654321
    return ret
                
ret = 987654321
for state in range(full_bit + 1):
    ret = min(ret, solve(state))

if ret == 987654321:
    ret = -1
print(ret)