import sys

a = [
    202021,
    20202021,
    202002021,
    202012021,
    202022021,
    202032021,
    202042021,
    202052021,
    202062021,
    202072021,
    202082021,
    202092021,
]
t = int(sys.stdin.readline().strip())
for _ in range(t):
    n = int(sys.stdin.readline().strip())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    d = {}
    for aa in arr:
        if aa in d:
            d[aa] += 1
        else:
            d[aa] = 1
    ret = 0
    d = dict(sorted(d.items()))
    for aa in a:
        for dd in d:
            if aa - dd < dd:
                break
            if aa - dd in d:
                ret += d[aa - dd] * d[dd]

    print(ret)
