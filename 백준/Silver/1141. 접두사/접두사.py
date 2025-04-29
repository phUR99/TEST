import sys
n = int(sys.stdin.readline().strip())
arr = [sys.stdin.readline().strip() for _ in range(n)]
adj = []
arr = sorted(arr)

def include(a, b):
    l = min(len(a), len(b))
    for i in range(l):
        if a[i] != b[i]:
            return False
    return True
ret = len(arr)
for i in range(n):
    for j in range(i+1, n):
        if include(arr[i], arr[j]):
            ret -=1 
            break
            
print(ret)
