def solution(key, lock):
    answer = False
    n = len(lock)
    m = len(key)
    cnt_lock = 0
    for i in range(n):
        for j in range(n):
            if lock[i][j] == 0:
                cnt_lock += 1
    
    padding_lock = [[3] * (n + (2 * m - 2)) for _ in range(n + (2 * m - 2))]
    for i in range(n):
        for j in range(n):
            padding_lock[m - 1 + i][m - 1 + j] = lock[i][j]
    turn = 0
    for i in range(m + n - 1):
        for j in range(m + n - 1):
            for _ in range(4):
                flag = False
                cnt = 0
                for k in range(m):
                    for t in range(m):
                        if padding_lock[i + k][j + t] >= 3:
                            continue
                        if padding_lock[i + k][j + t] == 0 and key[k][t] == 1:
                            cnt += 1
                        elif padding_lock[i + k][j + t] == 1 and key[k][t] == 0:
                            continue
                        else:
                            flag = True
                            break
                    if flag:
                        break
                if cnt == cnt_lock and not flag:
                    return True
                key = list(map(list, zip(*key[::-1])))
    return answer