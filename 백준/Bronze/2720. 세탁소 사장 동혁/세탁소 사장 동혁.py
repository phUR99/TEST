import sys
t = int(sys.stdin.readline().strip())
while t:
    t -= 1 
    n = int(sys.stdin.readline().strip())
    coins = [25, 10, 5, 1]
    ret = 0
    for coin in coins:
        print(n // coin, end=' ')
        n %= coin
    print()    