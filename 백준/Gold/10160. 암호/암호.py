N, K = map(int, input().split())
DP = [1] + [0] * N
for n in range(N):
    DP[n + 1] = (DP[n] * K - DP[n - 4] * 2 + DP[n - 6]) % (10**9 + 9)
print(DP[N])
