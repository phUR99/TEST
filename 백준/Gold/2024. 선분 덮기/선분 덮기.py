import heapq
m = int(input())
arr = []
while 1:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    heapq.heappush(arr, [a, -b])


st = 0
cnt = 0
while st < m :
    max_end = st
    while arr and arr[0][0] <= st:
        start, end = heapq.heappop(arr)
        max_end = max(max_end, -end)        
        
    if(max_end == st):
        print(0)
        exit()
    st = max_end
    cnt += 1
print(cnt)