#1. import queue로 library 사용 가능
import queue
#2. n, m 받기 가능
n, m = map(int, input().split())   
#3. 2차원 배열같은 경우 현재 형식으로 받기 가능
board = [list(map(int, input().split())) for _ in range(n)]
visit = [[False for j in range(m)] for _ in range(n)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def bfs(i, j):
    q = queue.Queue()

    ret = 1
    visit[i][j] = True
    q.put([i, j])
    while not q.empty() :

        x, y = q.get()

        for dir in range(4):
           nx = x + dx[dir] 
           ny = y + dy[dir]
           if nx < 0 or nx >= n or ny < 0 or ny >=m : continue
           if visit[nx][ny] == True or board[nx][ny] == 0: continue
           q.put([nx, ny])
           visit[nx][ny] = True
           ret +=1

    return ret


def solution():

    '''
    for i in range(n) : 
        for j in range(m) :
            print(board[i][j], end=" ")
        print()    
    '''
    cnt =0
    maxArea =0
    for i in range(n) : 
        for j in range(m) :
            if board[i][j] != 1 or visit[i][j] == True: continue
            maxArea = max(maxArea, bfs(i, j))
            cnt +=1

    print(cnt, maxArea, sep='\n')


solution()