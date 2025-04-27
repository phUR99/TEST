n = int(input())
arr = []

def solve(idx: int, val: int, now: int):
    if idx == 0: 
        arr.append(now)
        return
    for i in range(val):
        nxt = now * 10 + i
        solve(idx -1, i, nxt)
    
n -= 1
for i in range(1, 11):
    solve(i, 10, 0)

sorted(arr)

if len(arr) <= n:
    print(-1)
else:
    print(arr[n])