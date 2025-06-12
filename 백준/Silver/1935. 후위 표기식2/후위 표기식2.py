import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
line = input().strip()

arr = list(map(int, sys.stdin.readlines()))

stack = []
cur = 0
for word in line:
    if word.isalpha():
        stack.append(arr[ord(word) - ord("A")])
    else:
        b = stack.pop()
        a = stack.pop()
        if word == "*":
            stack.append(a * b)
        elif word == "/":
            stack.append(a / b)
        elif word == "+":
            stack.append(a + b)
        else:
            stack.append(a - b)

ret = stack.pop()
print(f"{ret:.2f}")
