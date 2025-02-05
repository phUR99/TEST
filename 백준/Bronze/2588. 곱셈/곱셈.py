a = int(input())
b = str(input())
arr =[int(i) for i in b]
arr.reverse()
for i in arr:
    print(i * a)
    
print(a * int(b))