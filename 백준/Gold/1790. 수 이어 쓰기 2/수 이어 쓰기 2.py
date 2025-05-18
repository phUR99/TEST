n, k = map(int, input().split())

ret = 0
iter = 9
cnt = 1
while iter * cnt < k:
    k -= iter * cnt
    ret += iter
    cnt += 1
    iter *= 10

ret = (ret + 1) + (k - 1) // cnt

if ret > n:
    print(-1)
else:
    print(str(ret)[(k - 1) % cnt])
