
answer = 0

def check(num, s): # num은 길이 s은 idx
    global answer
    idx = 0
    n = 0
    while idx < len(s):
        cnt = 1
        flag = s[idx: idx + num]
        while flag == s[idx + cnt * num: idx + (cnt + 1) * num]:
            cnt += 1
        if cnt == 1: # 겹치는 거 없음
            n += len(flag)
            idx += len(flag)
        else:
            idx += len(flag) * cnt
            n += len(str(cnt))
            n += len(flag)
    answer = min(answer, n)
    
def solution(s):
    global answer
    length = len(s)
    answer = length
    if length <= 2:
        return answer
    for num in range(1, (length // 2) + 1):
        check(num, s)
        
    
    return answer