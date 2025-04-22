import sys

string = sys.stdin.readline().strip()
freq : int = [0 for _ in range(26)]


for s in string:
    diff = ord(s) - ord('a')
    freq[diff] += 1
print(*freq)