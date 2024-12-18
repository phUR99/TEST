import sys
from functools import lru_cache

input = sys.stdin.read
data = input().split()

def solve():
    global index
    n, m = map(int, data[index:index+2])
    index += 2
    arr = list(map(int, data[index:index+m]))
    index += m

    @lru_cache(None)
    def caching(sum_, turn):
        if sum_ == 0:
            return 0
        ret = float('-inf')  # 매우 작은 초기값
        for i in range(m):
            if sum_ - turn * arr[i] >= 0:
                ret = max(ret, caching(sum_ - turn * arr[i], turn + 1) + arr[i])
        return ret

    result = caching(n, 1)
    if result < 0:
        result = -1
    print(result)

if __name__ == "__main__":
    index = 0
    t = int(data[index])
    index += 1
    for _ in range(t):
        solve()
