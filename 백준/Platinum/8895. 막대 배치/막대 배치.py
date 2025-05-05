import sys
sys.setrecursionlimit(10**6)

t = int(sys.stdin.readline().strip())


def solve():
    n, l, r = map(int, sys.stdin.readline().strip().split())
    
    
    dp = [[[0 for _ in range(r + 2)] for _ in range(l + 2)] for _ in range(n + 2)]
    dp[1][1][1]= 1
    for i in range(2, n+1):
        for j in range(1, l+1):
            for k in range(1, r+1):
                dp[i][j][k] += dp[i - 1][j - 1][k]
                dp[i][j][k] += dp[i - 1][j][k - 1]
                dp[i][j][k] += dp[i - 1][j][k] * (i - 2)
    print(dp[n][l][r])
    

for i in range(t):
    solve()
    
