import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())

arr = list(map(int, sys.stdin.readlines()))
arr = [(a, i) for i, a in enumerate(arr, 1)]
arr.sort()

tree = [0 for _ in range(4 * n)]


def update(left, right, node, target, value):
    if left > target or right < target:
        return

    tree[node] += value
    if left == right:
        return
    mid = (left + right) // 2
    update(left, mid, node * 2, target, value)
    update(mid + 1, right, node * 2 + 1, target, value)


def query(left, right, node, qleft, qright):
    if left > qright or right < qleft:
        return 0
    if qleft <= left and right <= qright:
        return tree[node]
    mid = (left + right) // 2
    return query(left, mid, node * 2, qleft, qright) + query(
        mid + 1, right, node * 2 + 1, qleft, qright
    )


for i in range(1, n + 1):
    update(1, n, 1, i, 1)

low = 0
high = n - 1
dir = 1
while low <= high:
    idx = -1
    ret = 0
    if dir:
        _, idx = arr[low]
        low += 1
        ret = query(1, n, 1, 1, idx - 1)
    else:
        _, idx = arr[high]
        high -= 1
        ret = query(1, n, 1, idx + 1, n)

    update(1, n, 1, idx, -1)
    print(f"{ret}\n")
    dir ^= 1
