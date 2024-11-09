n = int(input())

def dfs(count):
    if count == 3:
        if check():
            print("YES")
            exit()
        else:
            return
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 'X':
                arr[i][j] = 'O'
                dfs(count + 1)
                arr[i][j] = 'X'

moves = [(1, 0), (0, 1), (-1, 0), (0, -1)]


def check():
    for teacher in teacher_pos:
        i, j = teacher
        for move in moves:
            cnt = 0
            while 0 <= i + cnt * move[0] < n and 0 <= j + cnt * move[1] < n:
                ni = i + cnt * move[0]
                nj = j + cnt * move[1]
                if arr[ni][nj] == 'S':
                    return False
                elif arr[ni][nj] == 'O':
                    break
                cnt += 1
    return True

arr = []
teacher_pos = []
student_pos = []
for i in range(n):
    arr.append(list(input().split()))
    for j in range(n):
        if arr[i][j] == 'T':
            teacher_pos.append((i, j))
        elif arr[i][j] == 'S':
            student_pos.append((i, j))

# 여기서 O 넣어줄거임. arr[i][j] == 'X'인 것만 확인
dfs(0)
print("NO")
