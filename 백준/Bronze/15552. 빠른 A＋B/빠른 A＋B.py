import sys
t = int(sys.stdin.readline().strip())

while t:
    a, b = sys.stdin.readline().strip().split()
    sys.stdout.write(f"{int(a) + int(b)}\n")    
    t -= 1