import sys
t = int(sys.stdin.readline().strip())


def solve():
    string = sys.stdin.readline().strip()
    front = []
    back = []
    for s in string:
        if s == '<' and front:
            back.append(front.pop())
        if s == '>' and back:
            front.append(back.pop())
        if s == '-' and front:
            front.pop()
        if s.isalnum():
            front.append(s)

    front.extend(reversed(back))
    sys.stdout.write("".join(front) + '\n')
    return

    
while t:
    t -= 1
    solve()
     

    