

d = dict()


def col_check():
    cnt = 0
    for i in range(5):
        temp = 0
        for j in range(5):
            if check[j][i] == True:
                temp += 1
        if temp == 5:
            cnt += 1
    return cnt

def row_check():
    cnt = 0
    for i in range(5):
        temp = 0
        for j in range(5):
            if check[i][j] == True:
                temp += 1
        if temp == 5:
            cnt += 1
    return cnt

def diagonal_check():
    cnt = 0
    temp = 0
    temp1 =0
    for i in range(5):
        if check[i][i] == True:
            temp += 1
        if check[i][4 - i] == True:
            temp1 += 1
    if temp == 5:
        cnt += 1
    if temp1 == 5:
        cnt += 1
    return cnt



def is_bingo():
    col_cnt = col_check()
    row_cnt = row_check()
    diagonal_cnt = diagonal_check()
    if col_cnt + row_cnt + diagonal_cnt >= 3:
        return True
    return False


bingo = []
for i in range(5):
    bingo.append(list(map(int, input().split())))

for i in range(5):
    for j in range(5):
        d[bingo[i][j]] = (i, j)


arr = []
for _ in range(5):
    arr.extend(list(map(int, input().split())))

check = [[False] * 5 for _ in range(5)]

for i in range(25):
    a, b = d[arr[i]]
    check[a][b] = True
    if i >= 11:
        if is_bingo():
            break


print(i + 1)



