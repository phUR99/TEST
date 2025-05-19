import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readlines

arr = list(input())


for sentence in arr:
    if sentence[0] == ".":
        break
    s = []

    def solve(sentence):
        for word in sentence:
            if word == "[":
                s.append("[")
            elif word == "(":
                s.append("(")
            elif word == "]":
                if not s or s[-1] != "[":
                    print("no")
                    return
                else:
                    s.pop()

            elif word == ")":
                if not s or s[-1] != "(":
                    print("no")
                    return
                else:
                    s.pop()
        if s:
            print("no")
            return
        print("yes")

    solve(sentence=sentence)
