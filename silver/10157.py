C, R = map(int, input().split())

N = int(input())
if C * R < N:
    print("0")
else:
    i = 0
    j = -1
    cnt = 1
    arr = [[0] * R for _ in range(C)]
    flag = False
    while True:
        for move in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
            ni = i + move[0]
            nj = j + move[1]
            while 0 <= ni < C and 0 <= nj < R and arr[ni][nj] == 0:
                arr[ni][nj] = cnt
                i = ni
                j = nj
                if cnt == N:
                    flag = True
                    break
                cnt += 1
                ni = i + move[0]
                nj = j + move[1]
            if flag:
                break
        if flag:
            break
    print(i + 1, j + 1)
