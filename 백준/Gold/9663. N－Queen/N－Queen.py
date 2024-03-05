def check_condition(i, j):
    if diagonal_1[i - j + N- 1] == 0 and diagonal_2[(i + j)] == 0 and row[j] == 0:
        return True
    return False

def put_chess(i, j, num):
    arr[i][j] = num
    diagonal_1[i - j + N -1] = num
    row[j] = num
    diagonal_2[i + j] = num

def set_chess(i, N):
    global cnt
    if i == N:
        cnt += 1
    else:
        for j in range(0, N):
            if check_condition(i, j):
                put_chess(i, j, 1)
                set_chess(i + 1, N)
                put_chess(i, j, 0)

N = int(input())
cnt = 0
arr = [[0] * N for _ in range(N)]
diagonal_1 = [0] * (2 * N - 1)
diagonal_2 = [0] * (2 * N - 1)
row = [0] * N

# 첫 행을 체스판의 왼쪽 절반에만 놓고 탐색 시작
end = N // 2
for i in range(end):
    put_chess(0, i, 1)
    set_chess(1, N)
    put_chess(0, i, 0)
cnt *= 2
# 체스판이 홀수일 경우, 중앙에 퀸을 추가로 놓고 탐색
if N % 2:
    put_chess(0, end, 1)
    set_chess(1, N)
    put_chess(0, end, 0)
print(cnt)