a = int(input())
b = int(input())
pa = a / 100
pb = b / 100

dp = [[0.0 for _ in range(19)] for _ in range(19)]
dp[0][0] = 1.0

for _ in range(18):
    new_dp = [[0.0 for _ in range(19)] for _ in range(19)]
    for i in range(19):
        for j in range(19):
            val = dp[i][j]
            new_dp[i][j] += val * (1 - pa) * (1 - pb)
            if i < 18:
                new_dp[i + 1][j] += val * pa * (1 - pb)
            if j < 18:
                new_dp[i][j + 1] += val * (1 - pa) * pb
            if i < 18 and j < 18:
                new_dp[i + 1][j + 1] += val * pa * pb
    dp = new_dp
prime = {2, 3, 5, 7, 11, 13, 17}
ret = 0.0
for i in range(19):
    for j in range(19):
        if i in prime or j in prime:
            ret += dp[i][j]
print(ret)
