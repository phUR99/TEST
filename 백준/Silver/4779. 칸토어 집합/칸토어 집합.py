import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

arr = list(map(int, sys.stdin.readlines()))


def solve(t):
    l = 1
    for _ in range(t):
        l *= 3
    string = ["-"] * l

    def recursion(l, r):
        if l + 1 >= r:
            return
        ll = (l * 2 + r) // 3
        rr = (l + r * 2) // 3
        for i in range(ll, rr):
            string[i] = " "
        recursion(l, ll)
        recursion(rr, r)

    recursion(0, len(string))
    print("".join(string))


for a in arr:
    solve(a)
