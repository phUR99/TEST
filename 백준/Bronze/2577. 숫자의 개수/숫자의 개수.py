import sys
a, b, c = map(int, sys.stdin.readlines())
ret: str = str(a * b * c)

arr = [0 for _ in range(10)]
for i in ret:
    arr[ord(i)-ord('0')] += 1
print(*arr, sep= '\n')