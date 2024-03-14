n, m = map(int, input().split())
arr = [0 for i in range(m)]
#n까지의 정보가 필요하므로 range의 범위를 n+1로 설정해야함
isUsed = [False for i in range(n+1)]
def comb(cnt):
    
    if(cnt == m):
        #arr -> string의 형태로 변환시킨 후에 원소 + ' '의 형태로 출력함
        print(' '.join(map(str, arr)))
        return

    for i in range(1, n+1):
        if(isUsed[i] == True): continue
        arr[cnt] = i
        isUsed[i] = True
        comb(cnt+1)
        isUsed[i] = False

comb(0)
