import sys
n = int(sys.stdin.readline().strip())
'''
4 -> 4 + 5 -> 9 + 16

2 -> 3 -> 5 -> 5 + 9
'''

init: int = 2
for _ in range(n):
    
    init += (init - 1)
    #print(init)

print(init * init)
