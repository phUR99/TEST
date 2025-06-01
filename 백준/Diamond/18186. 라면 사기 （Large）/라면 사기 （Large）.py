import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write
n, b, c = map(int, input().split())

arr = list(map(int, input().split()))
arr.extend([0, 0])

if c >= b:
    print(f"{sum(arr) * b}")
    exit(0)

ret = 0
for i in range(n):
    if arr[i + 1] > arr[i + 2]:
        m = min(arr[i], arr[i + 1], arr[i + 1] - arr[i + 2])
        ret += m * (b + c)
        arr[i] -= m
        arr[i + 1] -= m
    if arr[i] and arr[i + 1] and arr[i + 2]:
        m = min(arr[i], arr[i + 1], arr[i + 2])
        ret += m * (b + 2 * c)
        arr[i] -= m
        arr[i + 1] -= m
        arr[i + 2] -= m
    if arr[i] and arr[i + 1]:
        m = min(arr[i], arr[i + 1])
        ret += m * (b + c)
        arr[i] -= m
        arr[i + 1] -= m
    if arr[i]:
        ret += arr[i] * b
        arr[i] -= m

print(f"{ret}")
