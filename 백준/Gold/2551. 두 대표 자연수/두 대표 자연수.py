import sys

n = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().strip().split()))
arr.sort()
avg = sum(arr) // n
print(
    arr[(n - 1) // 2],
    (
        avg
        if sum((x - avg) ** 2 for x in arr) <= sum((x - avg - 1) ** 2 for x in arr)
        else avg + 1
    ),
)
