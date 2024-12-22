import math
n = int(input())
while n > 0:
    a, b = map(int, input().split())
    print(math.lcm(a,b))
    n -=1