def check(s): # 안되면 false return 
    for mem in s:
        x, y, a = mem
        if a == 0: # 기둥
            if (x, y - 1, 0) in s or y == 0 or (x - 1, y, 1) in s or (x, y, 1) in s:
                pass
            else:
                return False
        else: # 보   
            if ((x - 1, y, 1) in s and (x + 1, y, 1) in s) or (x, y - 1, 0) in s or (x + 1, y - 1, 0) in s:
                pass
            else:
                return False 
    return True

def solution(n, build_frame):
    answer = [[]] 
    s = set()
    for oper in build_frame:
        if oper[3] == 1: # 설치
            s.add((oper[0], oper[1], oper[2]))
            if not check(s):
                s.remove((oper[0], oper[1], oper[2]))
        else: # 제거
            if (oper[0], oper[1], oper[2]) in s:
                s.remove((oper[0], oper[1], oper[2]))
                if not check(s):
                    s.add((oper[0], oper[1], oper[2]))
                
    ans = sorted(s)
    answer = list(map(list, ans))
    return answer