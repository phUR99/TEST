import sys
n = int(sys.stdin.readline().strip())

arr = []
def solve(idx:int, now:int, val:int):
    if idx == 0:
        arr.append(val)
        return
    
    for i in range(0, now):
        solve(idx-1, i, val*10 + i)
        
for i in range(0, 11):
    solve(i+1, 10, 0)
    
sorted(arr)
if n >= len(arr):
    sys.stdout.write(str(-1))
else:
    sys.stdout.write(str(arr[n]))