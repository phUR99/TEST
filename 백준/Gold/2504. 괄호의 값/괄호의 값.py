import sys
string = sys.stdin.readline().strip()
ret: int = 0
mul: int = 1
stack = []
for i, s in enumerate(string):
    if s == "(":
        mul *= 2
        stack.append("(")
    elif s == ")":
        if not stack or stack[-1] != "(":
            print(0)
            exit(0)
        stack.pop()
        if string[i-1] == '(':
            ret += mul
        mul //= 2        
    elif s == "[":
        mul *= 3
        stack.append("[")
    elif s == "]":
        if not stack or stack[-1] != "[":
            print(0)
            exit(0)
        stack.pop()
        if string[i-1] == '[':
            ret += mul
        mul //= 3
if stack:
    ret = 0
print(ret)