import sys
data = sys.stdin.read()
MAX = 300000
prefix = [1 for _ in range(MAX+1)]
arr = [*map(int, data.split())]
prefix[0] = prefix[1] = 0
i = 2
while i * i <= MAX:
    if(prefix[i] == 1) :
        for j in range(i*i, MAX+1, i):
            prefix[j] = 0
    i+=1
for i in range(2, MAX+1):
    prefix[i] = prefix[i-1] + prefix[i]


for ar in arr:
    if(ar == 0): break
    print(prefix[2*ar] - prefix[ar])
