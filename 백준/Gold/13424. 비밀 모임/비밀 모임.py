def solve():
    n, m = map(int, input().split())
    dist = [[987654321 for _ in range(n+1)] for _ in range(n+1)]    
    for i in range(1, n+1):
        dist[i][i] = 0
    
    for _ in range(m):
        a,b,c = map(int, input().split())
        dist[a][b] = min(dist[a][b], c)
        dist[b][a] = min(dist[b][a], c)
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    k = int(input())
    friend = [*map(int, input().split())]                
    sum = 987654321
    ret = -1
    for i in range(1, n+1):
        tmp = 0
        for f in friend:            
            tmp = tmp + dist[f][i]
        if tmp < sum:
            sum = tmp
            ret = i
    print(ret)

        
    
    
t = int(input())
for _ in range(t):
    solve()