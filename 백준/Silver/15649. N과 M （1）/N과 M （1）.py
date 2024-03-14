n, m = map(int, input().split())
arr = [0 for i in range(m)]
isUsed = [False for i in range(n+1)]
def comb(cnt):
    
    if(cnt == m):
        for i in range(m):
            print(arr[i], end=" ")
        print()
        return

    for i in range(1, n+1):
        if(isUsed[i] == True): continue
        arr[cnt] = i
        isUsed[i] = True
        comb(cnt+1)
        isUsed[i] = False

comb(0)