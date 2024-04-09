import sys

input = sys.stdin.readline

N, M = map(int, input().split())

def calc(i, j):
    global ans 
    
    for poses in blocks:
        sum_val = arr[i][j]
        for pos in poses:
            ni = i + pos[0]
            nj = j + pos[1]
            if 0 <= ni < N and 0 <= nj < M:
                sum_val += arr[ni][nj]
            else:
                break
        else:
            ans = max(ans, sum_val)
arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

blocks = [[(0,1), (0,2), (0,3)],[(1,0), (2,0), (3,0)], # ㅣ(회전)
	[(0,1), (1,0), (1,1)],  # ㅁ
    [(1,0), (2,0), (2,1)], [(0,1), (0,2), (1,0)], [(0,1), (1,1), (2,1)], [(0,1), (0,2),(-1,2)], # ㄴ(회전)
    [(0,1),(-1,1),(-2,1)], [(1,0), (1,1), (1,2)], [(0,1), (1,0), (2,0)], [(0,1), (0,2), (1,2)], # ㄴ대칭(회전)
    [(1,0), (1,1), (2,1)], [(0,1),(-1,1),(-1,2)],   # ㄹ(회전)
    [(1,0), (0,1),(-1,1)], [(0,1), (1,1), (1,2)],   # ㄹ대칭(회전)
    [(0,1), (0,2), (1,1)], [(-1,1),(0,1), (1,1)], [(0,1), (0,2),(-1,1)], [(1,0), (2,0), (1,1)]] # ㅏ(회전)

ans = 0

for i in range(N):
    for j in range(M):
        calc(i, j)

print(ans)