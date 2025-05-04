import sys 
sys.setrecursionlimit(10**6)
n = int(sys.stdin.readline().strip())
arr = [sys.stdin.readline().strip() for _ in range(n)]

def solve(left, right):
    if left > right:
        return ""
    if arr[left] > arr[right]:
        return arr[right] + solve(left, right-1)
    elif arr[left] < arr[right]:
        return arr[left] + solve(left+1, right)
    else:
        l, r = left, right
        while l <= r and arr[l] == arr[r]:
            l += 1 
            r -= 1
        if arr[l] < arr[r]:
            return arr[left] + solve(left +1, right)
        else:
            return arr[right] + solve(left, right-1)
    
ret = solve(0, n-1)
cnt = 0
for r in ret:
    cnt += 1
    print(r, end='')
    if cnt == 80:
        cnt = 0
        print()
