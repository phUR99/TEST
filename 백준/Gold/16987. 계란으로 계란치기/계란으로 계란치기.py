import sys

input = sys.stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]


def solve(idx):
    if idx == n:
        return sum(1 for s, w in arr if s <= 0)

    if arr[idx][0] <= 0:
        return solve(idx + 1)

    has_target = False
    for i in range(n):
        if i == idx:
            continue
        if arr[i][0] > 0:
            has_target = True
            break
    if not has_target:
        return solve(n)

    ret = 0
    for i in range(n):
        if i == idx or arr[i][0] <= 0:
            continue

        arr[idx][0] -= arr[i][1]
        arr[i][0] -= arr[idx][1]

        ret = max(ret, solve(idx + 1))

        arr[idx][0] += arr[i][1]
        arr[i][0] += arr[idx][1]

    return ret


print(solve(0))
