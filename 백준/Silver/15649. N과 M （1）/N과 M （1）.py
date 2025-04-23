from itertools import combinations, permutations
n, m = map(int, input().split())
ret = permutations([i + 1 for i in range(n)], m)
for r in ret:
    print(*r, sep= ' ')