num = [0 for _ in range(36)]
n = int(input())
for _ in range(n):
    Str = input()    
    cnt = 1
    for s in Str[::-1]:
        if(s.isdigit()) :
            num[int(s)] += cnt
        elif(s.isalpha()):
            num[ord(s) - ord('A')+10] += cnt
        cnt *= 36
k = int(input())

for _ in range(k):    
    idx = -1
    val = 0
    for i in range(35):
        if(num[i] * (35-i) > val):
            idx = i
            val = num[i] * (35-i)
    if(idx == -1) :break
    num[35] += num[idx]
    num[idx] = 0    
val = 0
for i in range(36):
    val += num[i] * i
#print(val)
ans = ''
while val > 0 :
    if(val % 36 < 10):
        ans += str(int(val % 36))
    else:
        ans += chr(ord('A') + int(val % 36) - 10)
    val //= 36
if ans :
    print(ans[::-1])
else :
    print(0)