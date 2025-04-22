import sys
front = list(sys.stdin.readline().strip())
back = []
m = int(sys.stdin.readline().strip())

while m:
    m -= 1
    query = list(sys.stdin.readline().strip().split())
    if query[0] == 'P':
        x = query[-1]
        front.append(x)
    elif query[0] == 'D':
        if back:
            front.append(back.pop())        
    elif query[0] == 'B':
        if front:
            front.pop()
    elif query[0] == 'L':
        if front:
            back.append(front.pop())

front.extend(reversed(back))
print(*front, sep="")